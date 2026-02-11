PORTNAME=	noctavox
DISTVERSION=	g20260211
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightweight TUI music player for local files
WWW=		https://github.com/Jaxx497/NoctaVox

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSL CC0-1.0 MIT \
		UNICODE UNICODE-DFS-2016 UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	Unicode Terms of Use
LICENSE_NAME_UNICODE-DFS-2016=	Unicode License Agreement - Data Files and Software (2016)
LICENSE_TEXT_UNICODE=	See https://spdx.org/licenses/Unicode-TOU.html
LICENSE_TEXT_UNICODE-DFS-2016=	See https://spdx.org/licenses/Unicode-DFS-2016.html
LICENSE_PERMS_UNICODE=		dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept
LICENSE_PERMS_UNICODE-DFS-2016=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	Jaxx497
GH_PROJECT=	NoctaVox
GH_TAGNAME=	1b04b23

CARGO_INSTALL_PATH=	${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

THEME_EXAMPLES_DIR=	${STAGEDIR}${EXAMPLESDIR}/themes_examples

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${RLN} vox ${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	cd ${WRKSRC}/docs && \
	${INSTALL_DATA} header.gif keymaps.md themes.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${THEME_EXAMPLES_DIR} && \
	(cd ${WRKSRC}/docs/theme_examples && ${COPYTREE_SHARE} . ${THEME_EXAMPLES_DIR})

.include <bsd.port.mk>
