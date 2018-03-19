# $FreeBSD$

PORTNAME=	alsa-sndio
DISTVERSION=	0.1
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	ALSA PCM sndio plugin

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libsndio.so:audio/sndio

USES=		gmake localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Duncaen

PLIST_FILES=	lib/alsa-lib/libasound_module_pcm_sndio.so

post-patch:
	@${REINPLACE_CMD} -e 's,-ldl,,' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/alsa-lib
	${INSTALL_LIB} ${WRKSRC}/libasound_module_pcm_sndio.so \
		${STAGEDIR}${PREFIX}/lib/alsa-lib

.include <bsd.port.mk>
