PORTNAME=	alchemist.el
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	lang
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Elixir Tooling Integration Into Emacs

LICENSE=	GPLv3

RUN_DEPENDS=	elixir-mode.el${EMACS_PKGNAMESUFFIX}>=0:lang/elixir-mode.el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	tonini

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
