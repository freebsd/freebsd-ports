# New ports collection makefile for:	google-gadgets
# Date created:		2008-06-08
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	google-gadgets
PORTVERSION=	0.10.0
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
		curl.4:${PORTSDIR}/ftp/curl \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/firefox-js.pc:${PORTSDIR}/www/firefox \
		${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20
USE_GCC=	4.2+
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include -Wno-deprecated-declarations" CPPFLAGS="-I${LOCALBASE}/include -Wno-deprecated-declarations" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-qt-host --enable-ltdl-install=no --disable-update-mime-database
USE_AUTOTOOLS=	libtool:15:env autoconf:261:env automake:110:env aclocal:110:env libltdl:15

OPTIONS=	DEBUGGING	"Enable debug output on runtime"	on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.am -exec ${GREP} -l pkgconfig {} \; | ${XARGS} ${REINPLACE_CMD} -e 's|^\(pkgconfigdir[[:space:]]*=\).*|\1 $$(prefix)/libdata/pkgconfig|'

pre-configure:
	@cd ${WRKSRC} && ${SH} autotools/bootstrap.sh && ${CP} ${AUTOMAKE_DIR}/mkinstalldirs libltdl/

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
