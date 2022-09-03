PORTNAME=	vim-colorschemes-legacy
DISTVERSION=	g20220816
CATEGORIES=	editors

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	Legacy colorschemes for Vim

LICENSE=	VIM
LICENSE_NAME=	VIM License
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	vim:editors/vim

USE_GITHUB=	yes
GH_ACCOUNT=	vim
GH_PROJECT=	colorschemes
GH_TAGNAME=	38384b9d9cd24028094e5c9a6ebd1a9950426a4a

NO_BUILD=	yes
NO_ARCH=	yes

VIMRUNTIME!=	make -C "${.CURDIR}/../vim" -V '$${DATADIR}/$${VIM_VER}'
DATADIR:=	${VIMRUNTIME}/colors/legacy
WRKSRC_SUBDIR=	legacy_colors

post-extract:
	${RM} ${WRKSRC}/README.md

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
