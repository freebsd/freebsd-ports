# New ports collection makefile for:	spring
# Date created:		10 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	spring
PORTVERSION=	0.80.4.1
CATEGORIES=	games
MASTER_SITES=	http://springrts.com/dl/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A project aiming to create a new and versatile RTS Engine

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		openal.0:${PORTSDIR}/audio/openal \
		GLEW.1:${PORTSDIR}/graphics/glew \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		IL.2:${PORTSDIR}/graphics/devil \
		ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		execinfo.1:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	relies on x86 floating-point math

USE_SDL=	sdl
USE_GL=		gl glu
USE_XORG=	x11 xcursor
USE_LDCONFIG=	yes
# built with < 4.0 will not sync in multiplayer...
# ...but it won't build with gcc42 from ports
#USE_GCC=	4.2+
MAKE_JOBS_SAFE=	yes

USE_CMAKE=	yes
CMAKE_ARGS=	-DDATADIR:STRING="share/${PORTNAME}" \
		-DMARCH_FLAG:STRING= \
		-DAIINTERFACES:STRING="NATIVE"

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PORTDOCS=	*

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

.include <bsd.port.mk>
