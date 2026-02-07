PORTNAME=	vim-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4-198
DISTVERSIONSUFFIX=	-gd36f381
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Async language server protocol plugin for vim and neovim
WWW=		https://github.com/prabirshrestha/vim-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	prabirshrestha

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
.for dir in doc autoload ftplugin plugin
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
.endfor

.include <bsd.port.mk>
