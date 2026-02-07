PORTNAME=	vim-colorschemes-legacy
DISTVERSION=	g20220816
PORTREVISION= 	1
CATEGORIES=	editors

MAINTAINER=	michael.osipov@innomotics.com
COMMENT=	Legacy colorschemes for Vim
WWW=		https://github.com/vim/colorschemes

LICENSE=	VIM
LICENSE_NAME=	VIM License
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	vim
GH_PROJECT=	colorschemes
GH_TAGNAME=	38384b9d9cd24028094e5c9a6ebd1a9950426a4a

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/vim/vimfiles/colors/legacy
WRKSRC_SUBDIR=	legacy_colors

post-extract:
	${RM} ${WRKSRC}/README.md

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
