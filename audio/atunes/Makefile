PORTNAME=	atunes
DISTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/latest-builds \
		SF/${PORTNAME}/${PORTNAME}/aTunes%20${DISTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured audio player and manager developed in Java
WWW=		https://sourceforge.net/projects/atunes/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

DEPRECATED=	last upstream version is from 2014, does not work with jdk11+
EXPIRATION_DATE=	2027-01-17

USES=		java
JAVA_VERSION=	8
DESKTOP_ENTRIES=	"aTunes" \
			"Audio player and manager" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"${PORTNAME}" \
			"Audio;AudioVideo;Java;" \
			true
EXTRACT_AFTER_ARGS=	--exclude ant*.jar \
			--exclude src \
			--exclude win_tools \
			--exclude *.dll \
			--exclude *.exe \
			--exclude *.so \
			--no-same-owner --no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	${PORTNAME}
SUB_LIST=	JAVA=${JAVA}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
PLIST_SUB=	VER=${DISTVERSION}

OPTIONS_DEFINE=		CDDA2WAV
OPTIONS_DEFAULT=	CDDA2WAV FLAC LAME MPLAYER VORBIS
OPTIONS_MULTI=		ENCODER ENGINE
OPTIONS_MULTI_ENCODER=	FLAC LAME VORBIS
OPTIONS_MULTI_ENGINE=	MPLAYER XINE

CDDA2WAV_DESC=		Ripper:  Enable cdrtools support
FLAC_DESC=		Encoder: Enable FLAC encoder
LAME_DESC=		Encoder: Enable lame MP3 encoder
MPLAYER_DESC=		Engine:  Use Mplayer
VORBIS_DESC=		Encoder: Enable vorbis OGG encoder
XINE_DESC=		Engine:  Use Xine

CDDA2WAV_RUN_DEPENDS=	cdda2wav:sysutils/cdrtools
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
VORBIS_RUN_DEPENDS=	ogg123:audio/vorbis-tools
XINE_LIB_DEPENDS=	libxine.so:multimedia/libxine

INSTALL_FILES=	aTunes.ico aTunes.jar splash.gif changelog.txt

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${INSTALL_FILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${DATADIR}/lib
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} settings ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
