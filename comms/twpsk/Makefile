PORTNAME=	twpsk
PORTVERSION=	4.3
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://wa0eir.bcts.info/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	takefu@airport.fm
COMMENT=	X psk31 client
WWW=		http://wa0eir.bcts.info/twpsk.html

LICENSE=	GPLv3

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		localbase motif pkgconfig xorg
USE_CXXSTD=	c++14
USE_XORG=	ice sm xt x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
