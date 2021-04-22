PORTNAME=	spring
PORTVERSION=	105.0.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Project aiming to create a new and versatile RTS Engine

LICENSE=	GPLv2+ BSD3CLAUSE BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libIL.so:graphics/devil \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libminizip.so:archivers/minizip \
		libfontconfig.so:x11-fonts/fontconfig \
		libcurl.so:ftp/curl \
		libunwind.so:devel/libunwind \
		libjsoncpp.so:devel/jsoncpp
BUILD_DEPENDS=	7z:archivers/p7zip

BROKEN_FreeBSD_12=	ld: error: undefined symbol: streflop_libm::__inline_isnanf(float)
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	relies on x86 floating-point math and amd64 atomic ops

USE_GITHUB=	yes
GH_TUPLE=	spring:Python:3bb6837:Python/AI/Interfaces/Python \
		spring:AAI:a15f45c:AAI/AI/Skirmish/AAI \
		spring:CircuitAI:91fd31e:CircuitAI/AI/Skirmish/CircuitAI \
		spring:HughAI:1a11f5a:HughAI/AI/Skirmish/HughAI \
		spring:KAIK:f6bdd3e:KAIK/AI/Skirmish/KAIK \
		spring:Shard:75339ae:Shard/AI/Skirmish/Shard \
		spring:SpringMapConvNG:76429b4:SprintMapConvNG/tools/mapcompile \
		spring:pr-downloader:67423a3:pr_downloader/tools/pr-downloader \
		spring:pyunitsync:6e1b3fd:pyunitsync/tools/unitsync/python

USES=		cmake compiler:c++11-lib desktop-file-utils gl localbase:ldflags \
		openal:al pkgconfig sdl shared-mime-info xorg
USE_GL=		gl glu glew
USE_SDL=	sdl2
USE_XORG=	x11 xcursor
CMAKE_ARGS=	-DDATADIR:STRING="share/${PORTNAME}" \
		-DDOCDIR:STRING="share/doc/${PORTNAME}" \
		-DAI_TYPES:STRING="NATIVE" \
		-DCMAKE_DISABLE_FIND_PACKAGE_Git=TRUE \
		-Wno-dev

MAKE_ENV=	PORTVERSION="${PORTVERSION:R}"  # build system expects 2 digit version

.if defined(WITH_SYNC_DEBUG)
CFLAGS=		# empty
CXXFLAGS=	# empty
CMAKE_ARGS+=	-DTRACE_SYNC=true -DSYNCDEBUG=true -DSYNCCHECK=true
CMAKE_BUILD_TYPE=DEBUG
.endif

# The check-target fails right now: https://springrts.com/mantis/view.php?id=4736
TEST_TARGET=	check

PORTDATA=	*

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_CMAKE_BOOL=	ENABLE_MANPAGES
MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			bash:shells/bash

post-patch:
.if defined(WITH_OPTIONAL_GS4)
	# allows minimal runtest with older hardware
	@${REINPLACE_CMD} -e '/GLEW_ARB_geometry_shader4/ s|CHECK_REQ_EXT|CHECK_OPT_EXT|' ${WRKSRC}/rts/Rendering/GlobalRendering.cpp
.endif
	@${REINPLACE_CMD} -e 's|/etc/\(spring/datadir\)|${PREFIX}/\1|g' \
		${WRKSRC}/rts/System/FileSystem/DataDirLocater.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/rts/build/cmake/*.cmake
	# XXX: recheck if this is still needed
	@${REINPLACE_CMD} -e 's|x1F3F|x0F3F|g' \
		${WRKSRC}/rts/System/Sync/FPUCheck.cpp

.include <bsd.port.mk>
