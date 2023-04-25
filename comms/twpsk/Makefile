PORTNAME=	twpsk
PORTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://wa0eir.bcts.info/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	takefu@airport.fm
COMMENT=	X psk31 client
WWW=		http://wa0eir.bcts.info/twpsk.html

LICENSE=	GPLv3

USES=		motif pkgconfig xorg
USE_XORG=	sm ice xt x11

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

GNU_CONFIGURE=	yes
CFLAGS+=	-L${LOCALBASE}/lib -I${PREFIX}/include
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
