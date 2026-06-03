PORTNAME=	elixir-mode.el
DISTVERSIONPREFIX=	v
PORTVERSION=	2.3.1
PORTREVISION=	21
CATEGORIES=	lang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Emacs major mode for Elixir
WWW=		https://github.com/elixir-lang/emacs-elixir

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang
GH_PROJECT=	emacs-elixir

CONFLICTS_INSTALL=	elixir-mode.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
