# $FreeBSD$

PORTNAME=	acoustid-fingerprinter
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/lalinsky/${PORTNAME}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	AcoustID audio fingerprint submission tool

LICENSE=	GPLv2

LIB_DEPENDS=	chromaprint:${PORTSDIR}/audio/chromaprint \
		tag:${PORTSDIR}/audio/taglib \
		avcodec${FFMPEG_SUFFIX}:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX}

USES=		cmake
USE_QT4=	gui network \
		qmake_build moc_build rcc_build uic_build
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS=	-DFFMPEG_SUFFIX:STRING=${FFMPEG_SUFFIX}
FFMPEG_SUFFIX?=	1

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

post-install:
.for i in 16 24 32 48 128 256
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/images/acoustid-fp-${i}.png ${PREFIX}/share/icons/hicolor/${i}x${i}/apps/acoustid-fingerprinter.png
.endfor
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/images/acoustid-fingerprinter.svg ${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
