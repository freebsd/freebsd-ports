# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	godot
PORTVERSION=	2.0
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	devel games

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Game engine and development environment

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libasound.so:audio/alsa-lib

USE_GITHUB=	yes
GH_ACCOUNT=	okamstudio

USES=		scons pkgconfig compiler
USE_XORG=	x11 xcursor xinerama
USE_GL=		glu
USE_OPENSSL=	yes

MAKE_ARGS+=	platform=x11
CXXFLAGS+=	-DRTAUDIO_ENABLED

OPTIONS_DEFINE=	EXAMPLES TOOLS
OPTIONS_DEFAULT=	EXAMPLES TOOLS
OPTIONS_SUB=	yes

TOOLS_DESC=	Include development tools (IDE)
TOOLS_MAKE_ARGS_ON=	tools=yes
TOOLS_MAKE_ARGS_OFF=	tools=no target=release

.include <bsd.port.pre.mk>

.if ${ARCH}==amd64 || ${ARCH}==powerpc64 || ${ARCH}==sparc64 || ${ARCH}==ia64
BITSUF=	.64
.else
BITSUF=	.32
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
LLSUF=	.llvm
MAKE_ARGS+=	use_llvm=yes
.else  # clang
USE_GCC=	yes
.if ${ARCH} == i386
CXXFLAGS+=	-march=i586
.endif
.endif # clang

.if ${PORT_OPTIONS:MTOOLS}
TOOLSUF=	.tools
.else
TOOLSUF=	.opt
.endif

BINSUFFIX=	${TOOLSUF}${BITSUF}${LLSUF}
PLIST_SUB+=	BINSUFF=${BINSUFFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|custom_build|${OPSYS}_Ports_build|' ${WRKSRC}/methods.py

do-install:
	@cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} godot.x11${BINSUFFIX} \
		${STAGEDIR}/${PREFIX}/bin/godot.x11${BINSUFFIX}
	@${LN} ${STAGEDIR}/${PREFIX}/bin/godot.x11${BINSUFFIX} \
		${STAGEDIR}/${PREFIX}/bin/godot

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${STAGEDIR}${DATADIR})
	${RM} ${STAGEDIR}${DATADIR}/demos/2d/hexamap/.fscache

.include <bsd.port.post.mk>
