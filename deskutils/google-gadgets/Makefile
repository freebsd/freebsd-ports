# New ports collection makefile for:	google-gadgets
# Date created:		2008-06-08
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	google-gadgets
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://google-gadgets-for-linux.googlecode.com/files/
DISTNAME=	${PORTNAME}-for-linux-${PORTVERSION}

MAINTAINER=	wahjava@gmail.com
COMMENT=	Google Desktop Gadgets

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/firefox-js.pc:${PORTSDIR}/www/firefox \
		${LOCALBASE}/libdata/pkgconfig/libcurl.pc:${PORTSDIR}/ftp/curl \
		${LOCALBASE}/libdata/pkgconfig/libxml-2.0.pc:${PORTSDIR}/textproc/libxml2 \
		${LOCALBASE}/libdata/pkgconfig/firefox-gtkmozembed.pc:${PORTSDIR}/www/firefox \
		${LOCALBASE}/libdata/pkgconfig/cairo.pc:${PORTSDIR}/graphics/cairo \
		${LOCALBASE}/libdata/pkgconfig/librsvg-2.0.pc:${PORTSDIR}/graphics/librsvg2 \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		curl.5:${PORTSDIR}/ftp/curl \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/firefox-js.pc:${PORTSDIR}/www/firefox \
		${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include -Wno-deprecated-declarations" CPPFLAGS="-I${LOCALBASE}/include -Wno-deprecated-declarations" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-ltdl-install=no
USE_AUTOTOOLS=	libtool:15:env autoconf:262:env automake:110:env aclocal:110:env libltdl:15
WANT_GNOME=	yes
USE_GNOME=	gnomehack
INSTALLS_ICONS=	yes

OPTIONS=	DEBUGGING	"Enable debug output on runtime"	on\
		GTK		"Build GTK Host"			on\
		QT		"Build Qt Host"				on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=This port needs 7.X or higher
.endif

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_GTK)
PLIST_SUB+=	GTK="@comment "
CONFIGURE_ARGS+=	--disable-gtk-host --disable-libggadget-gtk --disable-gtkmoz-browser-element --disable-gtk-system-framework
.elif defined(WITH_GTK)
USE_GNOME=	gtk20
PLIST_SUB+=	GTK=""
CONFIGURE_ARGS+=	--enable-gtk-host --with-gtkmozembed=firefox-gtkmozembed
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libstartup-notification-1.0.pc:${PORTSDIR}/x11/startup-notification
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
.endif

.if defined(WITHOUT_QT)
PLIST_SUB+=	QT="@comment "
CONFIGURE_ARGS+=	--disable-qt-host --disable-libggadget-qt --disable-qt-system-framework\
			--disable-qtwebkit-browser-element --disable-qt-script-runtime --disable-qt-xml-http-request
.else
USE_QT_VER=	4
QT_COMPONENTS=	webkit opengl gui corelib script network moc
PLIST_SUB+=	QT=""
CONFIGURE_ARGS+=	--enable-qt-host
.endif

.if defined(WITHOUT_QT) && defined(WITHOUT_GTK)
IGNORE=This port requires GTK or Qt host to be enabled
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.am -exec ${GREP} -l pkgconfig {} \; | ${XARGS} ${REINPLACE_CMD} -e 's|^\(pkgconfigdir[[:space:]]*=\).*|\1 $$(prefix)/libdata/pkgconfig|'

pre-configure:
	@cd ${WRKSRC} && ${SH} autotools/bootstrap.sh && ${CP} ${AUTOMAKE_DIR}/mkinstalldirs libltdl/
	@cd ${WRKSRC} && ${CHMOD} +x autotools/install-sh

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
