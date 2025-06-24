PORTNAME=	glib
DISTVERSION=	2.84.1
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)
WWW=		https://www.gtk.org/

LICENSE=	LGPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libffi.so:devel/libffi \
		libinotify.so:devel/libinotify \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	dbus-uuidgen:devel/dbus \
		update-desktop-database:devel/desktop-file-utils \
		update-mime-database:misc/shared-mime-info

FLAVORS=	default bootstrap
FLAVOR?=	${FLAVORS:[1]}
FLAVORS_SUB=	yes

default_EXTRACT_DEPENDS=	${LOCALBASE}/gobject-introspection-bootstrap/bin/g-ir-scanner:devel/gobject-introspection@bootstrap
default_USES=		trigger

bootstrap_PKGNAMESUFFIX=	-bootstrap

# iconv:wchar_t - our iconv in base doesn't support utf-8 -> wchar_t (boooo)
# (wchar_t is used by glibmm, rawtherapee triggered this)
USES=		compiler:c11 cpe gettext gnome iconv:wchar_t localbase:ldflags \
		meson perl5 pkgconfig python tar:xz ${${FLAVOR}_USES}
USE_LDCONFIG=	yes
USE_PERL5=	build
TRIGGERS=	gio-modules glib-schemas
MESON_ARGS=	-Db_lundef=false \
		-Ddefault_library=both \
		-Dfile_monitor_backend='libinotify-kqueue' \
		-Dinstalled_tests=false \
		-Dlibelf=disabled \
		-Dlibmount=disabled \
		-Druntime_dir=/var/run \
		-Dselinux=disabled \
		-Dsysprof=disabled \
		-Dsystemtap=disabled \
		-Dxattr=false
BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTSCOUT=	limitw:1,even
CPE_VENDOR=	gnome

CONFLICTS_INSTALL=	p5-Giovanni

_LIBVERSION=	0.${DISTVERSION:R:E}00.${DISTVERSION:E}
PLIST_SUB=	LIBVERSION=${_LIBVERSION}

OPTIONS_DEFINE=		DOCS FAM_ALTBACKEND MANPAGES NLS TEST
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_IMPLIES=		MANPAGES TEST
DOCS_MESON_TRUE=	documentation

FAM_ALTBACKEND_DESC=	Alternate file monitor backend

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_ENABLED=	man-pages

TEST_MESON_TRUE=	tests

# doesn't build yet
MESON_ARGS+=	-Ddtrace=disabled

.if ${FLAVOR:U} == bootstrap
MESON_ARGS+=	-Dintrospection=disabled -Ddocumentation=false -Dman-pages=disabled
OPTIONS_DEFINE=
PREFIX=		${LOCALBASE}/glib-bootstrap
PLIST_SUB+=	PORTDOCS='@comment ' NLS='@comment ' MANPAGES='@comment '
.else
BINARY_ALIAS+=	g-ir-scanner=${LOCALBASE}/gobject-introspection-bootstrap/bin/g-ir-scanner
MESON_ARGS+=	-Dintrospection=enabled
.endif

.if ${FLAVOR:U} == default
post-extract:
	${CP} -r ${LOCALBASE}/gobject-introspection-bootstrap/libdata/pkgconfig ${PKGCONFIG_LINKDIR}
	${CP} ${LOCALBASE}/glib-bootstrap/libdata/pkgconfig/* ${PKGCONFIG_LINKDIR}
.endif

pre-configure-FAM_ALTBACKEND-on:
	@${REINPLACE_CMD} -e 's|kqueue-helper.c|kqueue_fnm.c|g ; \
		s|.*kqueue-missing.c.*||g ; \
		s|.*dep-list.c.*||g' \
		${WRKSRC}/gio/kqueue/meson.build
	@${CP} -f ${FILESDIR}/gkqueuefilemonitor.c ${WRKSRC}/gio/kqueue/gkqueuefilemonitor.c
	@${CP} ${FILESDIR}/kqueue_fnm.c ${WRKSRC}/gio/kqueue/kqueue_fnm.c
	@${CP} ${FILESDIR}/kqueue_fnm.h ${WRKSRC}/gio/kqueue/kqueue_fnm.h

post-patch:
	${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|g' \
		${WRKSRC}/gio/gdbus-2.0/codegen/gdbus-codegen.in \
		${WRKSRC}/glib/gtester-report.in \
		${WRKSRC}/gobject/glib-genmarshal.in \
		${WRKSRC}/gobject/glib-mkenums.in
	${REINPLACE_CMD} -e '/inotify_init1/d' \
		-e '/inotify.h/d' \
		${WRKSRC}/meson.build
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/gio/xdgmime/xdgmime.c \
		${WRKSRC}/glib/gutils.c \
		${WRKSRC}/glib/tests/utils.c

CODEGENDIR=	${PREFIX}/share/glib-2.0/codegen

post-install-DOCS-on:
# this doc file gets created conditionally, so instead of adding another
# PLIST_SUB item just create an empty file if it is missing
	${TOUCH} ${STAGEDIR}${DOCSDIR}-2.0/const.VA_COPY_AS_ARRAY.html

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/GConf/gsettings
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gio/modules
# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
	${FIND} ${STAGEDIR}${PREFIX} -name \*.pyc -delete
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${CODEGENDIR} -f ${CODEGENDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${CODEGENDIR} -f ${CODEGENDIR:S;${PREFIX}/;;})
# install bash completion regardless if bash is present
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
.for file in gapplication gdbus gio gresource gsettings
	${INSTALL_DATA} ${WRKSRC}/gio/completion/${file} \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/
.endfor
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/installed-tests

pre-test:
	${LOCALBASE}/bin/dbus-uuidgen > /var/lib/dbus/machine-id

.include <bsd.port.mk>
