# $FreeBSD$

PORTNAME=	alchemist.el
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Elixir Tooling Integration Into Emacs

LICENSE=	GPLv3

RUN_DEPENDS=	elixir-mode.el>=0:${PORTSDIR}/lang/elixir-mode.el

USE_GITHUB=	yes
GH_ACCOUNT=	tonini

NO_ARCH=	yes
NO_BUILD=	yes
USE_EMACS=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/server
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/server/*.exs ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/server
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
