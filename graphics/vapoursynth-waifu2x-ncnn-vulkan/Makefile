PORTNAME=	vapoursynth-waifu2x-ncnn-vulkan
DISTVERSION=	r4
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Waifu2x (waifu2x-ncnn-vulkan) plugin for VapourSynth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers \
		${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
RUN_DEPENDS=	waifu2x-ncnn-vulkan>0:graphics/waifu2x-ncnn-vulkan

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	Nlzy
GH_TUPLE=	Tencent:ncnn:20210525:ncnn/deps/ncnn
CMAKE_ON=	NCNN_SYSTEM_GLSLANG
CMAKE_ARGS=	-DGLSLANG_TARGET_DIR:PATH="${LOCALBASE}/lib/cmake" \
		-DVAPOURSYNTH_HEADER_DIR:PATH="${LOCALBASE}/include/vapoursynth"
DATADIR=	${PREFIX}/lib/vapoursynth
PORTDATA=	libvsw2xnvk.so
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-patch:
# Drop submodule prefix for NCNN_SYSTEM_GLSLANG
	@${REINPLACE_CMD} 's,/glslang,,' ${WRKSRC_ncnn}/src/gpu.cpp
# Models from CLI package are same
	@${REINPLACE_CMD} -e '/pluginFilePath{/d' \
		-e '/pluginDir/s, =[^;]*,{"${LOCALBASE}/share/waifu2x-ncnn-vulkan"},' \
		${WRKSRC}/src/vsw2xnvk.cpp

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${PORTDATA:M*.so:S,^,${BUILD_WRKSRC}/,} \
		${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
