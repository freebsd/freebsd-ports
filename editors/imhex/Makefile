PORTNAME=	imhex
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors
MASTER_SITES=	https://git.sr.ht/~danyspin97/xdgpp/blob/f01f810714443d0f10c333d4d1d9c0383be41375/:xdg
DISTFILES=	xdg.hpp:xdg
DIST_SUBDIR=	imhex

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Hex editor for reverse engineers and programmers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 powerpc
NOT_FOR_ARCHS_REASON=	__uint128_t and __int128_t are not supported
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		btzy-nativefiledialog-extended-${GH_TAG_NATIVEFILEDIALOG}_GH0${EXTRACT_SUFX} \
		fmtlib-fmt-${GH_TAG_FMT}_GH0${EXTRACT_SUFX} \
		VirusTotal-yara-${GH_TAG_YARA}_GH0${EXTRACT_SUFX}

BUILD_DEPENDS=	glm>0:math/glm \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libglfw.so:graphics/glfw \
		libharfbuzz.so:print/harfbuzz \
		libmbedtls.so:security/mbedtls \
		libtre.so:textproc/libtre

USES=		cmake gnome pkgconfig python:3.8+ xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11 xcb xau xdmcp
USE_GITHUB=	yes

GH_ACCOUNT=	WerWolv
GH_PROJECT=	ImHex
GH_TUPLE=	btzy:nativefiledialog-extended:${GH_TAG_NATIVEFILEDIALOG}:nativefiledialog \
		fmtlib:fmt:${GH_TAG_FMT}:fmt \
		VirusTotal:yara:${GH_TAG_YARA}:yara
GH_TAG_FMT=	6271406
GH_TAG_NATIVEFILEDIALOG=	300203a
GH_TAG_YARA=	1842271

CMAKE_ARGS=	-DUSE_SYSTEM_CURL=ON

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS NLS
NLS_USES=	gettext

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/xdg.hpp ${WRKSRC}/external/xdgpp
	${CP} -R ${WRKSRC_fmt}/* ${WRKSRC}/external/fmt
	${CP} -R ${WRKSRC_nativefiledialog}/* ${WRKSRC}/external/nativefiledialog
	${CP} -R ${WRKSRC_yara}/* ${WRKSRC}/external/yara/yara

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
