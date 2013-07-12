# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	spring
PORTVERSION=	0.82.7.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/springrts/springrts/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A project aiming to create a new and versatile RTS Engine

BROKEN=		Does not build with recent boost

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		IL:${PORTSDIR}/graphics/devil \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		execinfo:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	relies on x86 floating-point math

USE_SDL=	sdl
USE_OPENAL=	al
USE_GL=		glew
USE_XORG=	x11 xcursor
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

USES=		cmake
CMAKE_ARGS=	-DDATADIR:STRING="share/${PORTNAME}" \
		-DMARCH_FLAG:STRING= \
		-DAI_TYPES:STRING="NATIVE" \
		-DMANDIR:STRING="man" \
		-DCREATE_MAN_PAGES:BOOL=false

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_SYNC_DEBUG)
CFLAGS=		# empty
CXXFLAGS=	# empty
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=DEBUG2 -DTRACE_SYNC=true -DSYNCDEBUG=true
.endif

post-patch:
	@${REINPLACE_CMD} -E -e '/FIND_PACKAGE.*(Python|JNI)/ d' \
		${WRKSRC}/tools/unitsync/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/etc/\(spring/datadir\)|${PREFIX}/\1|g; \
		/AddDirs.*GetBinaryPath/ d' \
		${WRKSRC}/rts/System/FileSystem/DataDirLocater.cpp
	@${REINPLACE_CMD} -e 's|x1F3F|x0F3F|g' \
		${WRKSRC}/rts/System/FPUCheck.h
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/rts/build/cmake/*.cmake
	@${REINPLACE_CMD} -e 's|execinfo|${LOCALBASE}/lib/libexecinfo.so|' \
		${WRKSRC}/rts/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/rts/System/Platform/Misc.cpp

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "userdocs DevGuide.html HowTo* \
		SelectionKeys.txt StartScriptFormat.txt changelog.txt" ${DOCSDIR}/
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
