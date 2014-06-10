# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.13.2
CATEGORIES=	lang elisp

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Emacs lisp module for the PHP language

USE_GITHUB=	yes
GH_ACCOUNT=	ejmr
GH_PROJECT=	${PORTNAME:S/.el$//}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	44cf5ce

NO_BUILD=	yes
PLIST_FILES=	share/emacs/site-lisp/php-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/php-mode.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp/php-mode.el

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
