PORTNAME=	go-mode.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pat@patmaddox.com
COMMENT=	Emacs mode for the Go programming language
WWW=		https://github.com/dominikh/go-mode.el

LICENSE=	BSD3CLAUSE

USES=			emacs
EMACS_NO_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dominikh
GH_PROJECT=	go-mode.el

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
