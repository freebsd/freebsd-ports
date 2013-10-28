# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	musescore
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/mscore/mscore/MuseScore-${PORTVERSION}/
DISTNAME=	mscore-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free music composition & notation software

LICENSE=	GPLv2

BUILD_DEPENDS=	qtscriptgenerator>0:${PORTSDIR}/devel/qtscriptgenerator
LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
RUN_DEPENDS=	qtscriptgenerator>0:${PORTSDIR}/devel/qtscriptgenerator

USE_BZIP2=	yes
USES=		cmake:outsource
USE_QT4=	corelib designer gui network script scripttools svg webkit xml \
		linguist_build moc_build qmake_build rcc_build uic_build
CMAKE_SOURCE_PATH=	${WRKSRC}/mscore
CMAKE_ARGS=	-DBUILD_ALSA:BOOL=OFF
ALL_TARGET=	lrelease all
MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/mscore-${PORTVERSION}

PORTDOCS=	ChangeLog NEWS README README.scripts

OPTIONS_DEFINE=	DOCS JACK PORTAUDIO
OPTIONS_DEFAULT=PORTAUDIO

OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CMAKE_ON=		-DBUILD_JACK:BOOL=ON
JACK_CMAKE_OFF=		-DBUILD_JACK:BOOL=OFF

PORTAUDIO_BUILD_DEPENDS=portaudio2>=0:${PORTSDIR}/audio/portaudio2
PORTAUDIO_RUN_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
PORTAUDIO_CMAKE_ON=	-DBUILD_PORTAUDIO:BOOL=ON
PORTAUDIO_CMAKE_OFF=	-DBUILD_PORTAUDIO:BOOL=OFF

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|-g -Wall|-Wall|g'
# add newline
.for file in mscore.cpp updatechecker.h webpage.cpp
	@${ECHO_CMD} >> ${WRKSRC}/mscore/mscore/${file}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/mscore/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
