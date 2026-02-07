PORTNAME=	imhex
PORTVERSION=	1.38.1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors
MASTER_SITES=	https://git.sr.ht/~danyspin97/xdgpp/blob/f01f810714443d0f10c333d4d1d9c0383be41375/:xdg \
		https://gitlab.com/EvelynTSMG/imhex-bastion-pats/-/archive/${GL_TAG_IMHEX_BASTION_PATS}/:bastion \
		https://gitlab.com/EvelynTSMG/imhex-ffx-pats/-/archive/${GL_TAG_IMHEX_FFX_PATS}/:ffx
DISTFILES=	xdg.hpp:xdg \
		imhex-bastion-pats-${GL_TAG_IMHEX_BASTION_PATS}.tar.bz2:bastion \
		imhex-ffx-pats-${GL_TAG_IMHEX_FFX_PATS}.tar.bz2:ffx
DIST_SUBDIR=	imhex

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Hex editor for reverse engineers and programmers
WWW=		https://github.com/WerWolv/ImHex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libglfw.so:graphics/glfw \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libinotify.so:devel/libinotify \
		liblz4.so:archivers/liblz4 \
		libmbedtls.so:security/mbedtls3 \
		libzstd.so:archivers/zstd

USES=		cmake desktop-file-utils gl gnome pkgconfig python xorg
USE_GL=		gl glu opengl
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11 xcb xau xdmcp
USE_GITHUB=	yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		btzy-nativefiledialog-extended-${GH_TAG_NATIVEFILEDIALOG}_GH0${EXTRACT_SUFX} \
		capstone-engine-capstone-${GH_TAG_CAPSTONE}_GH0${EXTRACT_SUFX} \
		CLIUtils-CLI11-${GH_TAG_CLI11}_GH0${EXTRACT_SUFX} \
		Martinsos-edlib-${GH_TAG_EDLIB}_GH0${EXTRACT_SUFX} \
		fmtlib-fmt-${GH_TAG_FMT}_GH0${EXTRACT_SUFX} \
		mity-md4c-${GH_TAG_MD4C}_GH0${EXTRACT_SUFX} \
		rockdreamer-throwing_ptr-${GH_TAG_THROWING_PTR}_GH0${EXTRACT_SUFX} \
		sammycage-plutovg-${GH_TAG_PLUTOVG}_GH0${EXTRACT_SUFX} \
		VirusTotal-yara-${GH_TAG_YARA}_GH0${EXTRACT_SUFX} \
		WerWolv-Disassembler-${GH_TAG_DISASSEMBLER}_GH0${EXTRACT_SUFX} \
		WerWolv-HashLibPlus-${GH_TAG_HASHLIBPLUS}_GH0${EXTRACT_SUFX} \
		WerWolv-ImHex-Patterns-${GH_TAG_IMHEX_PATTERNS}_GH0${EXTRACT_SUFX} \
		WerWolv-PatternLanguage-${GH_TAG_PATTERN_LANGUAGE}_GH0${EXTRACT_SUFX} \
		WerWolv-libromfs-${GH_TAG_LIBROMFS}_GH0${EXTRACT_SUFX} \
		WerWolv-libwolv-${GH_TAG_LIBWOLV}_GH0${EXTRACT_SUFX} \
		WerWolv-lunasvg-${GH_TAG_LUNASVG}_GH0${EXTRACT_SUFX} \
		imhex-bastion-pats-${GL_TAG_IMHEX_BASTION_PATS}.tar.bz2 \
		imhex-ffx-pats-${GL_TAG_IMHEX_FFX_PATS}.tar.bz2

GH_ACCOUNT=	WerWolv
GH_PROJECT=	ImHex
GH_TUPLE=	btzy:nativefiledialog-extended:${GH_TAG_NATIVEFILEDIALOG}:nativefiledialog \
		capstone-engine:capstone:${GH_TAG_CAPSTONE}:capstone \
		CLIUtils:CLI11:${GH_TAG_CLI11}:cli11 \
		Martinsos:edlib:${GH_TAG_EDLIB}:edlib \
		fmtlib:fmt:${GH_TAG_FMT}:fmt \
		mity:md4c:${GH_TAG_MD4C}:md4c \
		rockdreamer:throwing_ptr:${GH_TAG_THROWING_PTR}:throwing_ptr \
		sammycage:plutovg:${GH_TAG_PLUTOVG}:plutovg \
		VirusTotal:yara:${GH_TAG_YARA}:yara \
		WerWolv:Disassembler:${GH_TAG_DISASSEMBLER}:disassembler \
		WerWolv:HashLibPlus:${GH_TAG_HASHLIBPLUS}:hashlibplus \
		WerWolv:ImHex-Patterns:${GH_TAG_IMHEX_PATTERNS}:imhex_patterns \
		WerWolv:PatternLanguage:${GH_TAG_PATTERN_LANGUAGE}:pattern_language \
		WerWolv:libromfs:${GH_TAG_LIBROMFS}:libromfs \
		WerWolv:libwolv:${GH_TAG_LIBWOLV}:libwolv \
		WerWolv:lunasvg:${GH_TAG_LUNASVG}:lunasvg

GH_TAG_CAPSTONE=	9a0a160
GH_TAG_CLI11=	bfffd37
GH_TAG_DISASSEMBLER=	7235352
GH_TAG_EDLIB=	0ddc23e
GH_TAG_FMT=	407c905
GH_TAG_HASHLIBPLUS=	1823dd1
GH_TAG_IMHEX_PATTERNS=	ImHex-v${PORTVERSION}
GH_TAG_LIBROMFS=	fa444f2
GH_TAG_LIBWOLV=	b0c9416
GH_TAG_LUNASVG=	83c58df
GH_TAG_MD4C=	481fbfb
GH_TAG_NATIVEFILEDIALOG=	86d5f20
GH_TAG_PATTERN_LANGUAGE=	ImHex-v${PORTVERSION}
GH_TAG_PLUTOVG=	57f82ac
GH_TAG_THROWING_PTR=	cd28490
GH_TAG_YARA=	f44a895

GL_TAG_IMHEX_BASTION_PATS=	e6deed4
GL_TAG_IMHEX_FFX_PATS=	199879e

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include -fexperimental-library -D_LIBCPP_ENABLE_EXPERIMENTAL

CMAKE_ARGS=	-DUSE_SYSTEM_NLOHMANN_JSON=OFF -DIMHEX_STRIP_RELEASE=OFF \
		-DIMHEX_PLUGINS_IN_SHARE=ON -DIMHEX_OFFLINE_BUILD=ON \
		-DIMHEX_USE_GTK_FILE_PICKER=ON -DIMHEX_IGNORE_BAD_CLONE=ON \
		-DIMHEX_IGNORE_BAD_COMPILER=ON -DIMHEX_BUNDLE_PLUGIN_SDK=OFF \
		-DIMHEX_PLUGIN_LIBRARY_PLUGIN=OFF

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS NLS
NLS_USES=	gettext

.include <bsd.port.pre.mk>

post-extract:
	${CP} -R ${WRKSRC_disassembler}/* ${WRKSRC}/lib/external/disassembler
	${CP} -R ${WRKSRC_libromfs}/* ${WRKSRC}/lib/external/libromfs
	${CP} -R ${WRKSRC_libwolv}/* ${WRKSRC}/lib/external/libwolv
	${CP} -R ${WRKSRC_pattern_language}/* ${WRKSRC}/lib/external/pattern_language
	${CP} -R ${WRKSRC_cli11}/* ${WRKSRC}/lib/external/pattern_language/external/cli11
	${CP} -R ${WRKSRC_fmt}/* ${WRKSRC}/lib/external/pattern_language/external/fmt
	${CP} -R ${WRKSRC_throwing_ptr}/* ${WRKSRC}/lib/external/pattern_language/external/throwing_ptr
	${CP} ${DISTDIR}/${DIST_SUBDIR}/xdg.hpp ${WRKSRC}/lib/third_party/xdgpp
	${CP} -R ${WRKSRC_capstone}/* ${WRKSRC}/lib/third_party/capstone
	${CP} -R ${WRKSRC_edlib}/* ${WRKSRC}/lib/third_party/edlib
	${CP} -R ${WRKSRC_fmt}/* ${WRKSRC}/lib/third_party/fmt
	${CP} -R ${WRKSRC_hashlibplus}/* ${WRKSRC}/lib/third_party/HashLibPlus
	${CP} -R ${WRKSRC_lunasvg}/* ${WRKSRC}/lib/third_party/lunasvg
	${CP} -R ${WRKSRC_plutovg}/* ${WRKSRC}/lib/third_party/lunasvg/plutovg
	${CP} -R ${WRKSRC_md4c}/* ${WRKSRC}/lib/third_party/md4c
	${CP} -R ${WRKSRC_nativefiledialog}/* ${WRKSRC}/lib/third_party/nativefiledialog
	${CP} -R ${WRKSRC_yara}/* ${WRKSRC}/lib/third_party/yara/yara
	${MKDIR} ${WRKDIR}/.build/_deps/imhex_patterns_src
	${CP} -R ${WRKSRC_imhex_patterns}/* ${WRKDIR}/.build/_deps/imhex_patterns_src
	${CP} -R ${WRKDIR}/imhex-bastion-pats-${GL_TAG_IMHEX_BASTION_PATS}/* ${WRKDIR}/.build/_deps/imhex_patterns_src/patterns/bastion
	${CP} -R ${WRKDIR}/imhex-ffx-pats-${GL_TAG_IMHEX_FFX_PATS}/* ${WRKDIR}/.build/_deps/imhex_patterns_src/patterns/ffx

post-patch:
	${CP} -R ${WRKSRC}/lib/external/libwolv/* ${WRKSRC}/lib/external/pattern_language/external/libwolv

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
