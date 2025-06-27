PORTNAME=	vapoursynth-waifu2x-ncnn-vulkan
DISTVERSION=	r5
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Waifu2x (waifu2x-ncnn-vulkan) plugin for VapourSynth
WWW=		https://github.com/Nlzy/vapoursynth-waifu2x-ncnn-vulkan

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
GH_TUPLE=	KhronosGroup:glslang:11.9.0-19-g86ff4bca:glslang/deps/ncnn/glslang \
		Tencent:ncnn:20210525:ncnn/deps/ncnn
CMAKE_ARGS=	-DVAPOURSYNTH_HEADER_DIR:PATH="${LOCALBASE}/include/vapoursynth"
DATADIR=	${PREFIX}/lib/vapoursynth
PORTDATA=	libvsw2xnvk.so
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-patch:
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
