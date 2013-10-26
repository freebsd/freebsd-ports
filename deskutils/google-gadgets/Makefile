# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	google-gadgets
PORTVERSION=	0.11.2
PORTREVISION=	9
CATEGORIES=	deskutils
MASTER_SITES=	http://google-gadgets-for-linux.googlecode.com/files/
DISTNAME=	${PORTNAME}-for-linux-${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Google Desktop Gadgets

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

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
		curl:${PORTSDIR}/ftp/curl \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

BROKEN=		does not link

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -Wno-deprecated-declarations
CONFIGURE_ARGS=	--disable-werror --enable-ltdl-install=no --with-browser-plugins-dir=${LOCALBASE}/lib/browser_plugins
USE_AUTOTOOLS=	libtool:env autoconf:env automake:env aclocal:env libltdl
WANT_GNOME=	yes
USES=	pathfix
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DEBUGGING GTKWEBKIT MOZILLA
OPTIONS_DEFAULT=	DEBUGGING GTK QT GTKWEBKIT MOZILLA
OPTIONS_MULTI=	UI
OPTIONS_MULTI_UI=	GTK QT
UI_DESC=	Host toolkit
DEBUGGING_DESC=	debug output on runtime
GTK_DESC=	Build GTK Host
QT_DESC=	Build Qt Host
GTKWEBKIT_DESC=	Build with GTK Webkit support
MOZILLA_DESC=	Build with Mozilla support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT}
USE_QT4=	webkit opengl gui corelib script network moc_build
.endif

.if ${PORT_OPTIONS:MGTKWEBKIT}
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
LIB_DEPENDS+=	webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2
.endif

.if ${PORT_OPTIONS:MMOZILLA}
USE_GECKO=	libxul
.endif

.if ${PORT_OPTIONS:MGTKWEBKIT} && ! ${PORT_OPTIONS:MGTK}
PORT_OPTIONS+=	GTK

pre-everything::
	@${ECHO_MSG} "==> GTK Webkit or/and Mozilla support is enabled."
	@${ECHO_MSG} "==> Enabling GTK support. If this is not desired,"
	@${ECHO_MSG} "==> please rerun 'make config'."
.endif

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include -Wno-deprecated-declarations

.if ${PORT_OPTIONS:MDEBUGGING}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MGTK}
USE_GNOME=	gtk20
PLIST_SUB+=	GTK=""
CONFIGURE_ARGS+=	--enable-gtk-host
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libsoup-2.4.pc:${PORTSDIR}/devel/libsoup
LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CONFIGURE_ARGS+=	--with-ssl-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
.else
PLIST_SUB+=	GTK="@comment "
CONFIGURE_ARGS+=	--disable-gtk-host \
			--disable-libggadget-gtk \
			--disable-gtkmoz-browser-element \
			--disable-gtk-system-framework \
			--disable-webkit-script-runtime \
			--disable-gtkwebkit-browser-element \
			--disable-soup-xml-http-request
.endif

.if ${PORT_OPTIONS:MGTKWEBKIT}
PLIST_SUB+=	GTKWEBKIT=""
PLIST_SUB+=	GTKWEBKIT="@comment "
.else
CONFIGURE_ARGS+=	--disable-webkit-script-runtime	--disable-gtkwebkit-browser-element
.endif

.if ${PORT_OPTIONS:MMOZILLA}
PLIST_SUB+=	MOZILLA=""
.else
PLIST_SUB+=	MOZILLA="@comment "
CONFIGURE_ARGS+=	--disable-smjs-script-runtime	--disable-gtkmoz-browser-element
.endif

.if ${PORT_OPTIONS:MQT}
PLIST_SUB+=	QT=""
CONFIGURE_ARGS+=	--enable-qt-host
.else
PLIST_SUB+=	QT="@comment "
CONFIGURE_ARGS+=	--disable-qt-host --disable-libggadget-qt --disable-qt-system-framework\
			--disable-qtwebkit-browser-element --disable-qt-script-runtime --disable-qt-xml-http-request
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.am -exec ${GREP} -l pkgconfig {} \; | ${XARGS} ${REINPLACE_CMD} -e 's|^\(pkgconfigdir[[:space:]]*=\).*|\1 $$(prefix)/libdata/pkgconfig|'

pre-configure:
	@cd ${WRKSRC} && ${SH} autotools/bootstrap.sh && ${CP} ${AUTOMAKE_DIR}/mkinstalldirs libltdl/
	@cd ${WRKSRC} && ${CHMOD} +x autotools/install-sh

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
