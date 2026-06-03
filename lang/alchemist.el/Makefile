PORTNAME=	alchemist.el
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	21
CATEGORIES=	lang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Elixir Tooling Integration Into Emacs
WWW=		https://github.com/tonini/alchemist.el

LICENSE=	GPLv3

RUN_DEPENDS=	elixir-mode.el>=0:lang/elixir-mode.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	tonini

CONFLICTS_INSTALL=	alchemist.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server/lib
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/alchemist-server/*.exs ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server
	(cd ${WRKSRC}/alchemist-server/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/alchemist-server/lib)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
