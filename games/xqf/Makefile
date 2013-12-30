# Created by: steve farrell
# $FreeBSD$

PORTNAME=	xqf
PORTVERSION=	1.0.5
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server browser for many popular 3D action games

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_GNOME=	intlhack
USES=		gettext gmake pkgconfig
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lX11" # uses XGetWindowAttributes but doesn't link with X11

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	GTK2 GEOIP BZIP2 DOCS
OPTIONS_DEFAULT=GTK2 GEOIP BZIP2

GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ENABLE=	gtk2

GEOIP_CONFIGURE_ENABLE=	geoip
GEOIP_LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP
BZIP2_CONFIGURE_ENABLE=	bzip2

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gdkpixbuf
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
