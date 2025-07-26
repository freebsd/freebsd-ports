PORTNAME=	openrct2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.24
CATEGORIES=	games
MASTER_SITES=	https://github.com/OpenRCT2/title-sequences/releases/download/v0.4.14/:sequence \
		https://github.com/OpenRCT2/objects/releases/download/v1.7.1/:object \
		https://github.com/OpenRCT2/OpenMusic/releases/download/v1.6/:openmsx \
		https://github.com/OpenRCT2/OpenSoundEffects/releases/download/v1.0.5/:opensfx
DISTFILES=	title-sequences.zip:sequence \
		objects.zip:object\
		openmusic.zip:openmsx \
		opensound.zip:opensfx

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source re-implementation of RollerCoaster Tycoon 2
WWW=		https://openrct2.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/licence.txt

NOT_FOR_ARCHS=	mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only for little-endian architectures

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libpng.so:graphics/png \
		libzip.so:archivers/libzip \
		libFLAC.so:audio/flac \
		libvorbisfile.so:audio/libvorbis \
		libspeexdsp.so:audio/speexdsp \
		libfontconfig.so:x11-fonts/fontconfig \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libicuuc.so:devel/icu \
		libbenchmark.so:devel/benchmark \
		libogg.so:audio/libogg

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		localbase:ldflags pkgconfig sdl shared-mime-info ssl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenRCT2
GH_PROJECT=	OpenRCT2
USE_GL=		gl
USE_LDCONFIG=	yes
USE_SDL=	sdl2

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS

post-patch:
	${MKDIR} ${WRKSRC}/data/sequence
	${MKDIR} ${WRKSRC}/data/object
	${MKDIR} ${WRKSRC}/data/assetpack
	${CP} ${WRKDIR}/*.parkseq ${WRKSRC}/data/sequence/
	${CP} -r ${WRKDIR}/official ${WRKDIR}/rct1 ${WRKDIR}/rct2 \
		${WRKDIR}/rct2tt ${WRKDIR}/rct2ww ${WRKDIR}/object/official \
		${WRKSRC}/data/object/
	${CP} -r ${WRKDIR}/assetpack ${WRKSRC}/data/

.include <bsd.port.mk>
