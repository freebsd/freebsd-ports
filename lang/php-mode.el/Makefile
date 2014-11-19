# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.15.0
CATEGORIES=	lang elisp

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A PHP mode for GNU Emacs

USE_GITHUB=	yes
GH_ACCOUNT=	ejmr
GH_PROJECT=	${PORTNAME:S/.el$//}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	3eab4d9

NO_BUILD=	yes
PLIST_FILES=	share/emacs/site-lisp/php-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/php-mode.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/php-mode.el

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
