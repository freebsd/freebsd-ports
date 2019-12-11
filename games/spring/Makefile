# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	spring
PORTVERSION=	98.0
PORTREVISION=	20
CATEGORIES=	games
MASTER_SITES=	SF/springrts/springrts/${PORTNAME}-${PORTVERSION} \
		http://springrts.com/dl/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Project aiming to create a new and versatile RTS Engine

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libboost_thread.so:devel/boost-libs \
		libIL.so:graphics/devil \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis
BUILD_DEPENDS=	7z:archivers/p7zip

# XXX: it should be possible to build it on i386, investigate
# (currently link fails on undefined reference to __sync_fetch_and_add_8)
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	relies on x86 floating-point math and amd64 atomic ops

USE_SDL=	sdl2
USE_GL=		gl glu glew
USE_XORG=	x11 xcursor
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes
DOS2UNIX_GLOB=	*.h *.hpp *.cpp

USES=		cmake:insource compiler:c++11-lib dos2unix gl openal:al sdl \
		tar:lzma xorg
USES+=		desktop-file-utils shared-mime-info
CMAKE_ARGS=	-DDATADIR:STRING="share/${PORTNAME}" \
		-DAI_TYPES:STRING="NATIVE" \
		-DDOCDIR:STRING="share/doc/${PORTNAME}" \
		-DCREATE_MAN_PAGES:BOOL=false \
		-DUSE_TCMALLOC:BOOL=false \
		-DUSE_LIBSQUISH:BOOL=false \
		-DUNITSYNC_PYTHON_WRAPPER:BOOL=false

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

# Do not exctract bundled copies of header files for 3rd-party packages:
EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions --exclude ${WRKSRC:T}/include

# The check-target fails right now: https://springrts.com/mantis/view.php?id=4736
TEST_TARGET=	check

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	MANPAGES PR_DOWNLOADER DOCS
OPTIONS_DEFAULT=MANPAGES PR_DOWNLOADER
OPTIONS_SUB=	yes

PR_DOWNLOADER_DESC=	Map and game downloader

MANPAGES_CMAKE_ON=	-DCREATE_MAN_PAGES:BOOL=true -DMANDIR:STRING="man"
MANPAGES_CMAKE_OFF=	-DCREATE_MAN_PAGES:BOOL=false
MANPAGES_BUILD_DEPENDS=	7z:archivers/p7zip \
			asciidoc:textproc/asciidoc \
			xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			bash:shells/bash
CXXFLAGS+=	-Wno-deprecated		# Too much noise

PR_DOWNLOADER_LIB_DEPENDS=libcurl.so:ftp/curl

.include <bsd.port.pre.mk>

.if defined(WITH_SYNC_DEBUG)
CFLAGS=		# empty
CXXFLAGS=	# empty
CMAKE_ARGS+=	-DTRACE_SYNC=true -DSYNCDEBUG=true
CMAKE_BUILD_TYPE=DEBUG2
.endif

.if ! ${PORT_OPTIONS:MPR_DOWNLOADER}
post-extract:
	@${RM} ${WRKSRC}/tools/pr-downloader/CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/etc/\(spring/datadir\)|${PREFIX}/\1|g' \
		${WRKSRC}/rts/System/FileSystem/DataDirLocater.cpp
	@${REINPLACE_CMD} -e 's|x1F3F|x0F3F|g' \
		${WRKSRC}/rts/System/Sync/FPUCheck.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/rts/build/cmake/*.cmake
	@${REINPLACE_CMD} -e 's|execinfo|/usr/lib/libexecinfo.so|' \
		${WRKSRC}/rts/CMakeLists.txt \
		${WRKSRC}/rts/builds/dedicated/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/rts/System/Platform/Misc.cpp
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}&|' \
		${WRKSRC}/doc/manpages/make_manpages.sh
.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e '/set(CREATE_MAN_PAGES)/ d' \
		${WRKSRC}/doc/CMakeLists.txt
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} generateVersionFiles

.include <bsd.port.post.mk>
