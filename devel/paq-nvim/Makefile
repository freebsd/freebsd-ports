PORTNAME=	paq-nvim
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel editors

MAINTAINER=	agh@riseup.net
COMMENT=	Minimal Neovim plugin manager
WWW=		https://github.com/savq/paq-nvim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	neovim>0:editors/neovim
RUN_DEPENDS=	git>0:devel/git \
		neovim>0:editors/neovim

USE_GITHUB=	yes
GH_ACCOUNT=	savq
GH_PROJECT=	${PORTNAME}

DATADIR=	${PREFIX}/share/nvim/site/pack/${PORTNAME:S|-nvim||g}/start/${PORTNAME}

NO_ARCH=	yes
SUB_FILES=	pkg-message

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

DOCS_DESC=	Plugin and project documentation

do-build:
	(cd ${WRKSRC} && \
		nvim -i NONE -u NONE -e --headless -c "helptags doc" -c "quit")

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for DATA in doc lua
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${DATA} ${STAGEDIR}${DATADIR})
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in CONTRIBUTING README
	${INSTALL_DATA} ${WRKSRC}/${DOC}.md \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
