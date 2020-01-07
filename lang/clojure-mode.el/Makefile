# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	clojure-mode.el
PORTVERSION=	5.11.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp module for the Clojure language

LICENSE=	GPLv3+

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	clojure-emacs
GH_PROJECT=	clojure-mode

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/clojure-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/clojure-mode-extra-font-locking.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/test.clj \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
