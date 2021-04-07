PORTNAME=	mio2jack
PORTVERSION=	g20180501
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Expose Sndio MIDI ports to JACK

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjack.so:audio/jack \
		libsndio.so:audio/sndio

USES=		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	martingms
GH_TAGNAME=	9d0de50b226539e3e61ad4f36aa74cfe160d2747

MAKEFILE=	/dev/null
ALL_TARGET=	mio2jack
LDFLAGS+=	-ljack -lsndio

PLIST_FILES=	bin/mio2jack

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mio2jack ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
