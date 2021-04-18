PORTNAME=	spectrogram
PORTVERSION=	20190725
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio visualization for sndio

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libsndio.so:audio/sndio

USES=		pkgconfig xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	dim13
GH_TAGNAME=	a5f5fef

PLIST_FILES=	bin/spectrogram

post-patch:
	${REINPLACE_CMD} -e 's|NOMAN=|MAN=|g' \
		-e 's|-lsndio|-lm -lsndio|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spectrogram \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
