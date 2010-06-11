# New ports collection makefile for:	google-gadgets
# Date created:		2008-06-08
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	google-gadgets
PORTVERSION=	0.11.2
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://google-gadgets-for-linux.googlecode.com/files/
DISTNAME=	${PORTNAME}-for-linux-${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Google Desktop Gadgets

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/libcurl.pc:${PORTSDIR}/ftp/curl \
		${LOCALBASE}/libdata/pkgconfig/libxml-2.0.pc:${PORTSDIR}/textproc/libxml2 \
		${LOCALBASE}/libdata/pkgconfig/cairo.pc:${PORTSDIR}/graphics/cairo \
		${LOCALBASE}/libdata/pkgconfig/librsvg-2.0.pc:${PORTSDIR}/graphics/librsvg2 \
		${LOCALBASE}/libdata/pkgconfig/libstartup-notification-1.0.pc:${PORTSDIR}/x11/startup-notification \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		curl.6:${PORTSDIR}/ftp/curl \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -Wno-deprecated-declarations" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-ltdl-install=no --with-browser-plugins-dir=${LOCALBASE}/lib/browser_plugins
USE_AUTOTOOLS=	libtool:22:env autoconf:262:env automake:110:env aclocal:110:env libltdl:22
WANT_GNOME=	yes
USE_GNOME=	gnomehack
INSTALLS_ICONS=	yes

OPTIONS=	DEBUGGING	"Enable debug output on runtime"	on\
		GTK		"Build GTK Host"			on\
		QT		"Build Qt Host"				on\
		GTKWEBKIT	"Build with GTK Webkit support"		on\
		MOZILLA		"Build with Mozilla support"		on

.include <bsd.port.options.mk>

.if defined(WITH_QT)
USE_QT_VER=	4
QT_COMPONENTS=	webkit opengl gui corelib script network moc_build
.endif

.if defined(WITH_GTKWEBKIT)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
LIB_DEPENDS+=	webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
.endif

.if defined(WITH_MOZILLA)
USE_GECKO=	libxul firefox mozilla seamonkey xulrunner
.endif

.if defined(WITHOUT_GTKWEBKIT) && defined(WITHOUT_MOZILLA) && defined(WITH_GTK)
IGNORE=	gtk host requires GTK Webkit or/and Mozilla support to be enabled. Please, rerun 'make config'
.elif defined(WITH_GTKWEBKIT) && defined(WITHOUT_GTK)
.undef WITHOUT_GTK
WITH_GTK=yes

pre-everything::
	@${ECHO_MSG} "==> GTK Webkit or/and Mozilla support is enabled."
	@${ECHO_MSG} "==> Enabling GTK support. If this is not desired,"
	@${ECHO_MSG} "==> please rerun 'make config'."
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -Wno-deprecated-declarations"

.if ${OSVERSION} < 700000
IGNORE=	needs 7.X or higher
.endif

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_GTK)
PLIST_SUB+=	GTK="@comment "
CONFIGURE_ARGS+=	--disable-gtk-host \
			--disable-libggadget-gtk \
			--disable-gtkmoz-browser-element \
			--disable-gtk-system-framework \
			--disable-webkit-script-runtime \
			--disable-gtkwebkit-browser-element \
			--disable-soup-xml-http-request
.elif defined(WITH_GTK)
USE_GNOME=	gtk20
PLIST_SUB+=	GTK=""
CONFIGURE_ARGS+=	--enable-gtk-host
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libsoup-2.4.pc:${PORTSDIR}/devel/libsoup
LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CONFIGURE_ARGS+=	--with-ssl-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt

.endif

.if defined(WITHOUT_GTKWEBKIT)
PLIST_SUB+=	GTKWEBKIT="@comment "
CONFIGURE_ARGS+=	--disable-webkit-script-runtime	--disable-gtkwebkit-browser-element
.elif defined(WITH_GTKWEBKIT)
PLIST_SUB+=	GTKWEBKIT=""
.endif

.if defined(WITHOUT_MOZILLA)
PLIST_SUB+=	MOZILLA="@comment "
CONFIGURE_ARGS+=	--disable-smjs-script-runtime	--disable-gtkmoz-browser-element
.elif defined(WITH_MOZILLA)
PLIST_SUB+=	MOZILLA=""
.endif

.if defined(WITHOUT_QT)
PLIST_SUB+=	QT="@comment "
CONFIGURE_ARGS+=	--disable-qt-host --disable-libggadget-qt --disable-qt-system-framework\
			--disable-qtwebkit-browser-element --disable-qt-script-runtime --disable-qt-xml-http-request
.else
PLIST_SUB+=	QT=""
CONFIGURE_ARGS+=	--enable-qt-host
.endif

.if defined(WITHOUT_QT) && defined(WITHOUT_GTK)
IGNORE=	requires GTK or/and Qt host to be enabled. Please, rerun 'make config'
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.am -exec ${GREP} -l pkgconfig {} \; | ${XARGS} ${REINPLACE_CMD} -e 's|^\(pkgconfigdir[[:space:]]*=\).*|\1 $$(prefix)/libdata/pkgconfig|'

pre-configure:
	@cd ${WRKSRC} && ${SH} autotools/bootstrap.sh && ${CP} ${AUTOMAKE_DIR}/mkinstalldirs libltdl/
	@cd ${WRKSRC} && ${CHMOD} +x autotools/install-sh

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
