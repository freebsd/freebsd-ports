# $FreeBSD$

PORTNAME=	alchemist.el
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Elixir Tooling Integration Into Emacs

LICENSE=	GPLv3

RUN_DEPENDS=	elixir-mode.el>=0:lang/elixir-mode.el

USE_GITHUB=	yes
GH_ACCOUNT=	tonini

NO_ARCH=	yes
NO_BUILD=	yes
USE_EMACS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server/lib
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/alchemist-server/*.exs ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server
	cd ${WRKSRC}/alchemist-server/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
