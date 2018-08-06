# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.19.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	PHP mode for GNU Emacs

LICENSE=	GPLv3

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-php
GH_PROJECT=	${PORTNAME:S/.el$//}

NO_ARCH=	yes
PLIST_FILES=	share/emacs/site-lisp/php-mode.el \
		share/emacs/site-lisp/php-mode.elc \
		share/emacs/site-lisp/php-project.el \
		share/emacs/site-lisp/php-project.elc

do-install:
	${INSTALL_DATA} \
		${WRKSRC}/php-mode.el \
		${WRKSRC}/php-mode.elc \
		${WRKSRC}/php-project.el \
		${WRKSRC}/php-project.elc \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/

.include <bsd.port.mk>
