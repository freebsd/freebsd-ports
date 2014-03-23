# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/glib20/Makefile 18634 2013-07-26 10:42:35Z kwm $

PORTNAME=	glib
PORTVERSION=	2.36.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

LICENSE=	LGPL20

USE_XZ=		yes
PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre \
		libffi.so:${PORTSDIR}/devel/libffi

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
# iconv:wchar_t - our iconv in base doesn't support utf-8 -> wchar_t (boooo)
# (wchar_t is used by glibmm, rawtherapee triggered this)
USES=		gettext gmake iconv:wchar_t pathfix pkgconfig shebangfix perl5
USE_GNOME=	ltverhack
USE_PYTHON=	yes
PYTHON_PY3K_PLIST_HACK=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc \
		--disable-man --without-xml-catalog \
		--with-pcre=system \
		--disable-fam
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	*/*.pl glib/gen-iswide-table.py

OPTIONS_DEFINE=	COLLATION_FIX DEBUG
COLLATION_FIX_DESC=	fix string collation

.include <bsd.port.pre.mk>

# doesn't build yet
#.if (${OSVERSION} < 800000) \
#	|| (${OSVERSION} >= 800000 && ${OSVERSION} < 802000)
#	|| (${OSVERSION} >= 900000 && ${OSVERSION} < 900021)
CONFIGURE_ARGS+=--disable-dtrace
#.else
#CONFIGURE_ARGS+=--enable-dtrace
#.endif

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=	--with-libiconv=native
.else
CONFIGURE_ARGS+=	--with-libiconv=gnu
.endif

.if ${ARCH} == powerpc64
EXTRA_PATCHES=	${FILESDIR}/extra-arch-powerpc64
.endif

# Let glib use asm code for implementing atomic ops on i386 and amd64.
.if ${ARCH} == "i386"
GLIB_ARCH=	i486
.elif ${ARCH} == "amd64"
GLIB_ARCH=	x86_64
.else
GLIB_ARCH=	${ARCH}
.endif
CONFIGURE_TARGET=${GLIB_ARCH}-portbld-freebsd${OSREL}

.if ${PORT_OPTIONS:MCOLLATION_FIX}
LIB_DEPENDS+=	libicui18n.so:${PORTSDIR}/devel/icu
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-glib_Makefile.in \
		${FILESDIR}/extra-patch-glib_gunicollate.c
# Disable it until someone can figure why it causes net-im/pidgin crashed.
# http://www.freebsd.org/cgi/query-pr.cgi?pr=175930 see comment by ed@
#CONFIGURE_ENV+=	CFLAGS="-D__STDC_ISO_10646__"
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug=yes \
			--disable-silent-rules
.else
CONFIGURE_ARGS+=	--disable-modular-tests
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|/usr/share/locale/locale|${LOCALBASE}/share/locale/locale|g' \
			${WRKSRC}/glib/gutils.c
	@${REINPLACE_CMD} -e 's|/lib/dbus/machine-id|/db/dbus/machine-id|g' \
		${WRKSRC}/gio/gdbusaddress.c ${WRKSRC}/gio/gdbusprivate.c \
		${WRKSRC}/po/*.po
	@${REINPLACE_CMD} -e 's|inotify_support=yes|inotify_support=no| ; \
		s|-Werror|| ; \
		s|#define HAVE_SYS_INOTIFY_H 1||' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/GConf/gsettings

.include <bsd.port.post.mk>

.endif
