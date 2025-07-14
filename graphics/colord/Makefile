PORTNAME=	colord
PORTVERSION=	1.4.8
CATEGORIES=	graphics
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Manage color profiles to accurately color input/output devices
WWW=		https://www.freedesktop.org/software/colord

LICENSE=	LGPL21+

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgusb.so:devel/libgusb \
		libgudev-1.0.so:devel/libgudev \
		liblcms2.so:graphics/lcms2 \
		libpolkit-gobject-1.so:sysutils/polkit
RUN_DEPENDS=	hwdata>0:misc/hwdata

USERS=		colord
GROUPS=		colord

USES=		gettext gnome localbase meson pathfix pkgconfig sqlite tar:xz
USE_GNOME=	glib20 introspection:build

USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1
MESON_ARGS=	-Dsystemd=false -Dudev_rules=false \
		-Ddaemon_user=colord -Dlibcolordcompat=true \
		-Dpnp_ids=${LOCALBASE}/share/hwdata/pnp.ids

GLIB_SCHEMAS=	org.freedesktop.ColorHelper.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS COMPLETION MANPAGES PPROFILES SANE SENSOR TESTS VALA
OPTIONS_DEFAULT=COMPLETION MANPAGES VALA TESTS

COMPLETION_DESC=Build and install shell completions
PPROFILES_DESC=	Build extra print profiles (long build time)
SANE_DESC=	Enable SANE support
SENSOR_DESC=	Enable ArgyllCMS sensor
TESTS_DESC=	Build self tests
VALA_DESC=	Build Vala language bindings

DOCS_MESON_TRUE=		docs
COMPLETION_MESON_TRUE=		bash_completion
MANPAGES_MESON_TRUE=		man
PPROFILES_MESON_TRUE=		print_profiles
SANE_MESON_TRUE=		sane
SENSOR_MESON_TRUE=		argyllcms_sensor
TESTS_MESON_TRUE=		tests
VALA_MESON_TRUE=		vapi

COMPLETION_BUILD_DEPENDS=	bash-completion>=2.0:shells/bash-completion
DOCS_BUILD_DEPENDS=		gtkdoc-scan:textproc/gtk-doc
POLKIT_LIB_DEPENDS=		libpolkit-gobject-1.so:sysutils/polkit
POLKIT_CONFIGURE_ENABLE=	polkit
MANPAGES_BUILD_DEPENDS=		xsltproc:textproc/libxslt \
				docbook-xsl-ns>0:textproc/docbook-xsl-ns
SANE_LIB_DEPENDS=		libsane.so:graphics/sane-backends
SENSOR_BUILD_DEPENDS=		spotread:graphics/argyllcms
SENSOR_RUN_DEPENDS=		spotread:graphics/argyllcms
VALA_USES=			vala:build

GNOME_HTML_DIR=		${PREFIX}/share/gtk-doc/html

post-patch:
	@${REINPLACE_CMD} -e 's|lib/color\>|db/color|g' \
		-e 's|/usr/share/color|${PREFIX}/share/color|g' \
		-e 's|LOCALSTATEDIR "/lib/|LOCALSTATEDIR "/db/|g' \
		${WRKSRC}/src/cd-main.c \
		${WRKSRC}/lib/colord/cd-icc-store.c \
		${WRKSRC}/src/cd-profile.c
	@${REINPLACE_CMD} -e 's|@@DOCBOOK_MANPAGE_XSL@@|${LOCALBASE}/share/xsl/docbook-ns/manpages/docbook.xsl|' \
		${WRKSRC}/man/meson.build

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/colord/icc
	@${FIND} ${STAGEDIR}/var/lib -type d | ${TAIL} -r | ${XARGS} ${RMDIR}

post-stage-DOCS-on:
	cd ${WRKSRC}; ${COPYTREE_SHARE} NEWS ${STAGEDIR}${DOCSDIR}

add-plist-docs: ${STAGE_COOKIE}
	cd ${STAGEDIR}; ${FIND} ${DOCSDIR:C@^/@@} -type f | ${SED} -e 's@^@/@' >> ${TMPPLIST}
	cd ${STAGEDIR}; ${FIND} ${PREFIX:C@^/@@}/share/gtk-doc/html -mindepth 2 -type f | ${SED} -e 's@^@/@' >> ${TMPPLIST}

.include <bsd.port.mk>
