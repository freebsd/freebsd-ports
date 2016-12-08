# Created by: steve farrell
# $FreeBSD$

PORTNAME=	xqf
PORTVERSION=	1.0.5
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server browser for many popular 3D action games

RUN_DEPENDS=	qstat:games/qstat

USE_GNOME=	intlhack
USES=		gettext gmake pkgconfig
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	GTK2 GEOIP BZIP2 DOCS
OPTIONS_DEFAULT=GTK2 GEOIP BZIP2

GTK2_USE=		GNOME=gtk20
GTK2_USE_OFF=		GNOME=gdkpixbuf
GTK2_CONFIGURE_ENABLE=	gtk2

GEOIP_CONFIGURE_ENABLE=	geoip
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP

BZIP2_CONFIGURE_ENABLE=	bzip2

BROKEN_aarch64=		Fails to linkld: final link failed: Bad value

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
