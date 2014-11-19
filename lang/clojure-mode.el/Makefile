# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	clojure-mode.el
PORTVERSION=	2.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang elisp
DISTNAME=	clojure-mode-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp module for the Clojure language

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	clojure-emacs
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	cb3810a
GH_PROJECT=	clojure-mode

USE_EMACS=	yes

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/clojure-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/clojure-test-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
