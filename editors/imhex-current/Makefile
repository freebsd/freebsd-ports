PORTNAME=	imhex
PORTVERSION=	1.35.4
DISTVERSIONPREFIX=	v
CATEGORIES=	editors
MASTER_SITES=	https://git.sr.ht/~danyspin97/xdgpp/blob/f01f810714443d0f10c333d4d1d9c0383be41375/:xdg \
		https://gitlab.com/EvelynTSMG/imhex-bastion-pats/-/archive/${GL_TAG_IMHEX_BASTION_PATS}/:bastion \
		https://gitlab.com/EvelynTSMG/imhex-ffx-pats/-/archive/${GL_TAG_IMHEX_FFX_PATS}/:ffx
PKGNAMESUFFIX=	-current
DISTFILES=	xdg.hpp:xdg \
		imhex-bastion-pats-${GL_TAG_IMHEX_BASTION_PATS}.tar.bz2:bastion \
		imhex-ffx-pats-${GL_TAG_IMHEX_FFX_PATS}.tar.bz2:ffx
DIST_SUBDIR=	imhex

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Hex editor for reverse engineers and programmers (current version)
WWW=		https://github.com/WerWolv/ImHex

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc
NOT_FOR_ARCHS_REASON=	__uint128_t and __int128_t are not supported
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		btzy-nativefiledialog-extended-${GH_TAG_NATIVEFILEDIALOG}_GH0${EXTRACT_SUFX} \
		capstone-engine-capstone-${GH_TAG_CAPSTONE}_GH0${EXTRACT_SUFX} \
		CLIUtils-CLI11-${GH_TAG_CLI11}_GH0${EXTRACT_SUFX} \
		Martinsos-edlib-${GH_TAG_EDLIB}_GH0${EXTRACT_SUFX} \
		fmtlib-fmt-${GH_TAG_FMT}_GH0${EXTRACT_SUFX} \
		josuttis-jthread-${GH_TAG_JTHREAD}_GH0${EXTRACT_SUFX} \
		rockdreamer-throwing_ptr-${GH_TAG_THROWING_PTR}_GH0${EXTRACT_SUFX} \
		sammycage-lunasvg-${GH_TAG_LUNASVG}_GH0${EXTRACT_SUFX} \
		VirusTotal-yara-${GH_TAG_YARA}_GH0${EXTRACT_SUFX} \
		WerWolv-HashLibPlus-${GH_TAG_HASHLIBPLUS}_GH0${EXTRACT_SUFX} \
		WerWolv-ImHex-Patterns-${GH_TAG_IMHEX_PATTERNS}_GH0${EXTRACT_SUFX} \
		WerWolv-PatternLanguage-${GH_TAG_PATTERN_LANGUAGE}_GH0${EXTRACT_SUFX} \
		WerWolv-libromfs-${GH_TAG_LIBROMFS}_GH0${EXTRACT_SUFX} \
		WerWolv-libwolv-${GH_TAG_LIBWOLV}_GH0${EXTRACT_SUFX} \
		imhex-bastion-pats-${GL_TAG_IMHEX_BASTION_PATS}.tar.bz2 \
		imhex-ffx-pats-${GL_TAG_IMHEX_FFX_PATS}.tar.bz2

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libglfw.so:graphics/glfw \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libinotify.so:devel/libinotify \
		libmbedtls.so:security/mbedtls \
		libzstd.so:archivers/zstd

USES=		cmake desktop-file-utils gl gnome pkgconfig python xorg
USE_GL=		gl glu opengl
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11 xcb xau xdmcp
USE_GITHUB=	yes

CONFLICTS_INSTALL=	imhex-1.30.*

GH_ACCOUNT=	WerWolv
GH_PROJECT=	ImHex
GH_TUPLE=	btzy:nativefiledialog-extended:${GH_TAG_NATIVEFILEDIALOG}:nativefiledialog \
		capstone-engine:capstone:${GH_TAG_CAPSTONE}:capstone \
		CLIUtils:CLI11:${GH_TAG_CLI11}:cli11 \
		Martinsos:edlib:${GH_TAG_EDLIB}:edlib \
		fmtlib:fmt:${GH_TAG_FMT}:fmt \
		josuttis:jthread:${GH_TAG_JTHREAD}:jthread \
		rockdreamer:throwing_ptr:${GH_TAG_THROWING_PTR}:throwing_ptr \
		sammycage:lunasvg:${GH_TAG_LUNASVG}:lunasvg \
		VirusTotal:yara:${GH_TAG_YARA}:yara \
		WerWolv:HashLibPlus:${GH_TAG_HASHLIBPLUS}:hashlibplus \
		WerWolv:ImHex-Patterns:${GH_TAG_IMHEX_PATTERNS}:imhex_patterns \
		WerWolv:PatternLanguage:${GH_TAG_PATTERN_LANGUAGE}:pattern_language \
		WerWolv:libromfs:${GH_TAG_LIBROMFS}:libromfs \
		WerWolv:libwolv:${GH_TAG_LIBWOLV}:libwolv \

GH_TAG_CAPSTONE=	097c04d
GH_TAG_CLI11=	6c7b07a
GH_TAG_EDLIB=	931be2b
GH_TAG_FMT=	0041a40
GH_TAG_HASHLIBPLUS=	1823dd1
GH_TAG_IMHEX_PATTERNS=	ImHex-v1.35.4
GH_TAG_JTHREAD=	0fa8d39
GH_TAG_LIBROMFS=	03adcfd
GH_TAG_LIBWOLV=	0e3ba3a
GH_TAG_LUNASVG=	17b595a
GH_TAG_NATIVEFILEDIALOG=	c099aae
GH_TAG_PATTERN_LANGUAGE=	ImHex-v1.35.4
GH_TAG_THROWING_PTR=	cd28490
GH_TAG_YARA=	0e5b6bb

GL_TAG_IMHEX_BASTION_PATS=	e6deed4
GL_TAG_IMHEX_FFX_PATS=	199879e

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

CMAKE_ARGS=	-DUSE_SYSTEM_CURL=ON -DUSE_SYSTEM_NLOHMANN_JSON=OFF \
		-DIMHEX_STRIP_RELEASE=OFF -DIMHEX_PLUGINS_IN_SHARE=ON \
		-DIMHEX_OFFLINE_BUILD=ON -DIMHEX_USE_GTK_FILE_PICKER=ON \
		-DIMHEX_IGNORE_BAD_CLONE=ON -DIMHEX_IGNORE_BAD_COMPILER=ON

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS NLS
NLS_USES=	gettext

.include <bsd.port.pre.mk>

# Before LLVM 17 import into the base system
.if ((${OSREL:R} == 14 && ${OSVERSION} < 1400504) \
    || (${OSREL:R} == 15 && ${OSVERSION} < 1500006))
IGNORE=	requires libc++ of LLVM 17 on the base system
.endif

# After LLVM 18 import into the base system
.if ((${OSREL:R} == 15 && ${OSVERSION} >= 1500018) \
    || (${OSREL:R} == 14 && ${OSVERSION} >= 1400511) \
    || (${OSREL:R} == 13 && ${OSVERSION} >= 1303503))
CXXFLAGS+=	-fexperimental-library -D_LIBCPP_ENABLE_EXPERIMENTAL
.endif

post-extract:
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
	${CP} -R ${WRKSRC_nativefiledialog}/* ${WRKSRC}/lib/third_party/nativefiledialog
	${CP} -R ${WRKSRC_yara}/* ${WRKSRC}/lib/third_party/yara/yara
	${MKDIR} ${WRKDIR}/.build/_deps/imhex_patterns_src
	${CP} -R ${WRKSRC_imhex_patterns}/* ${WRKDIR}/.build/_deps/imhex_patterns_src
	${CP} -R ${WRKDIR}/imhex-bastion-pats-${GL_TAG_IMHEX_BASTION_PATS}/* ${WRKDIR}/.build/_deps/imhex_patterns_src/patterns/bastion
	${CP} -R ${WRKDIR}/imhex-ffx-pats-${GL_TAG_IMHEX_FFX_PATS}/* ${WRKDIR}/.build/_deps/imhex_patterns_src/patterns/ffx
# Before LLVM 18 import into the base system
.if ((${OSREL:R} == 15 && ${OSVERSION} < 1500018) \
    || (${OSREL:R} == 14 && ${OSVERSION} < 1400511) \
    || (${OSREL:R} == 13 && ${OSVERSION} < 1303503))
	${CP} -R ${WRKSRC_jthread}/* ${WRKSRC}/lib/third_party/jthread
.endif

post-patch:
	${CP} -R ${WRKSRC}/lib/external/libwolv/* ${WRKSRC}/lib/external/pattern_language/external/libwolv

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
