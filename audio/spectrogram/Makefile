# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	spectrogram
PORTVERSION=	20161017
CATEGORIES=	audio

MAINTAINER=	t@tobik.me
COMMENT=	Audio visualization for sndio

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libsndio.so:audio/sndio

USES=	pkgconfig
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	dim13
GH_TAGNAME=	432e96b

PLIST_FILES=	bin/spectrogram

post-patch:
	${REINPLACE_CMD} -e 's|NOMAN=|MAN=|g' \
		-e 's|-lsndio|-lm -lsndio|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spectrogram \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
