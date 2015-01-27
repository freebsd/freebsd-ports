# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	godot
PORTVERSION=	1.0
CATEGORIES=	devel games

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Game engine and development environment

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libasound.so:${PORTSDIR}/audio/alsa-lib

USE_GITHUB=	yes
GH_ACCOUNT=	okamstudio
GH_PROJECT=	godot
GH_TAGNAME=	${PORTVERSION}-stable
GH_COMMIT=	7eb5d04

USES=		scons pkgconfig compiler
USE_XORG=	x11 xcursor
USE_GL=		glu
USE_OPENSSL=	yes
# uses pkg-config to find ssl - pkg-config only finds port version
WITH_OPENSSL_PORT=	yes

MAKE_ARGS+=	platform=x11

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

.if ${COMPILER_TYPE} == clang
.if ${OSVERSION} < 900000
BROKEN=	clang fails to link on 8.x
.endif
LLSUF=	.llvm
MAKE_ARGS+=	use_llvm=yes
.else  # clang
USE_GCC=	4.8+
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
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${STAGEDIR}${DATADIR})
	${RM} ${STAGEDIR}${DATADIR}/demos/2d/hexamap/.fscache
.endif

.include <bsd.port.post.mk>
