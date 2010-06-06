# New ports collection makefile for:	spring
# Date created:		10 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	spring
PORTVERSION=	0.81.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/springrts/springrts/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A project aiming to create a new and versatile RTS Engine

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		IL.2:${PORTSDIR}/graphics/devil \
		ogg.7:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		execinfo.1:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	relies on x86 floating-point math

USE_SDL=	sdl
USE_OPENAL=	al
USE_GL=		glew
USE_XORG=	x11 xcursor
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

USE_CMAKE=	yes
CMAKE_ARGS=	-DDATADIR:STRING="share/${PORTNAME}" \
		-DMARCH_FLAG:STRING= \
		-DAIINTERFACES:STRING="NATIVE"

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_SYNC_DEBUG)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=DEBUG2 -DTRACE_SYNC=true -DSYNCDEBUG=true
.endif

.if ${OSVERSION} < 700042
BROKEN=		does not build in 6.x
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

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
