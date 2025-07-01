PORTNAME=	simgear
PORTVERSION=	2024.1.1
CATEGORIES=	devel games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Toolkit for 3D games and simulations
WWW=		https://www.flightgear.org/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libosg.so:graphics/osg \
		libexpat.so:textproc/expat2 \
		libcurl.so:ftp/curl

USES=		alias cmake compiler:c++17-lang cpe gl jpeg openal:al,alut \
		tar:bzip2 xorg

USE_GITLAB=	yes
GL_ACCOUNT=	flightgear
GL_TAGNAME=	v${PORTVERSION}

USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL=		gl glu glut

USE_LDCONFIG=	yes

LDFLAGS_gcc=	-losgDB
LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}

CMAKE_ARGS+=	-DSYSTEM_EXPAT:BOOL=ON \
		-DENABLE_TESTS:BOOL=OFF

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DENABLE_SIMD:BOOL=OFF
.endif

post-patch:
# Avoid conflict with C++20 <version> - used version file is simgear-version
	@${RM} ${WRKSRC}/version

.include <bsd.port.post.mk>
