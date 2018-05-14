# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.19.1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang elisp

MAINTAINER=	knu@FreeBSD.org
COMMENT=	PHP mode for GNU Emacs

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	ejmr
GH_PROJECT=	${PORTNAME:S/.el$//}

NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	share/emacs/site-lisp/php-mode.el \
		share/emacs/site-lisp/php-project.el

do-install:
	${INSTALL_DATA} \
		${WRKSRC}/php-mode.el \
		${WRKSRC}/php-project.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/

.include <bsd.port.mk>
