PORTNAME=	fcitx5-hazkey
DISTVERSION=	0.2.1
CATEGORIES=	japanese textproc
MASTER_SITES=	LOCAL/tagattie/${PORTNAME}:swiftpackages
DISTFILES=	${PORTNAME}-${DISTVERSION}-swift-packages${EXTRACT_SUFX}:swiftpackages

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hazkey input method for fcitx5
WWW=		https://hazkey.hiira.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git \
		glslc:graphics/shaderc \
		vulkan-headers>0:graphics/vulkan-headers \
		${LOCALBASE}/swift6/bin/swift:lang/swift6
LIB_DEPENDS=	libprotobuf-lite.so:devel/protobuf \
		libvulkan.so:graphics/vulkan-loader \
		libFcitx5Core.so:textproc/fcitx5

USES=		cmake gettext-tools gl qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	7ka-Hiira
GH_PROJECT=	hazkey
GH_TUPLE=	azooKey:azooKey_dictionary_storage:e9796e052793c0d4ac304a27f9db4b7beb7cd43c:azooKey_dictionary_storage/hazkey-server/azooKey_dictionary_storage \
		azooKey:azooKey_emoji_dictionary_storage:08f82252fb90ef8f0949a7e3c554e9e1787ce121:azooKey_emoji_dictionary_storage/hazkey-server/azooKey_emoji_dictionary_storage \
		7ka-hiira:llama.cpp:10295c26a2a18c3c48863b179c5e6bf34a4057d1:llama_cpp/hazkey-server/llama.cpp

USE_GL=		gl opengl
USE_QT=		base tools:build

BINARY_ALIAS=	swift=${LOCALBASE}/swift6/bin/swift

post-extract:
	@${MKDIR} ${WRKDIR}/.build/hazkey-server/swift-build
	@${MV} ${WRKDIR}/swift-packages-cache/* \
		${WRKDIR}/.build/hazkey-server/swift-build

post-patch:
	@${REINPLACE_CMD} -E 's/os\(Windows\) \|\| os\(Linux\)/& || os(FreeBSD)/' \
		${WRKDIR}/.build/hazkey-server/swift-build/checkouts/AzooKeyKanaKanjiConverter/Package.swift

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/hazkey-settings
	@${RLN} ${STAGEDIR}${PREFIX}/lib/hazkey/hazkey-settings \
		${STAGEDIR}${PREFIX}/bin/hazkey-settings
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/hazkey/hazkey-server \
		${STAGEDIR}${PREFIX}/lib/hazkey/libllama/*.so \
		${STAGEDIR}${PREFIX}/lib/hazkey/libllama/backends/*.so

#
# target(s) for port maintainer(s)
#
make-swift-packages-cache: extract
	@${MKDIR} ${WRKDIR}/swift-packages-cache
	@cd ${WRKSRC}/hazkey-server && \
	${SETENV} ${MAKE_ENV} ${LOCALBASE}/swift6/bin/swift package \
		--scratch-path=${WRKDIR}/swift-packages-cache \
		resolve
	@${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
		${TAR} -czf ${WRKDIR}/${PORTNAME}-${DISTVERSION}-swift-packages${EXTRACT_SUFX} \
		-C ${WRKDIR} swift-packages-cache

.include <bsd.port.mk>
