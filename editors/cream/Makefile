# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	cream
PORTVERSION=	0.43
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/Cream/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gvim extension with many features

LICENSE=	GPLv3+

RUN_DEPENDS=	${LOCALBASE}/bin/gvim:editors/vim

NO_ARCH=	yes
NO_BUILD=	yes

USES=		desktop-file-utils

PLIST_SUB=	VIM_VER="${VIM_VER}"

OPTIONS_DEFINE=	DOCS

VIMRUNTIME!=	cd ../vim && ${MAKE} -V PORTVERSION:R:S,\.,,g
VIM_VER?=	vim${VIMRUNTIME}

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} cream \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/${VIM_VER}/cream
	(cd ${WRKSRC} && ${INSTALL_DATA} creamrc *.vim \
		${STAGEDIR}${PREFIX}/share/vim/${VIM_VER}/cream)
.for f in addons bitmaps help lang
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} \
		${STAGEDIR}${PREFIX}/share/vim/${VIM_VER}/cream)
.endfor
	(cd ${WRKSRC} && ${INSTALL_DATA} cream.desktop \
		${STAGEDIR}${PREFIX}/share/applications)
	(cd ${WRKSRC} && ${INSTALL_DATA} cream.png cream.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in docs docs-html
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} \
		${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
