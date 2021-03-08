# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php-mode.el
PORTVERSION=	1.24.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	PHP mode for GNU Emacs

LICENSE=	GPLv3

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-php
GH_PROJECT=	${PORTNAME:S/.el$//}

NO_ARCH=	yes

LISP_FILES=	lisp/php-align.el \
		lisp/php-align.elc \
		lisp/php-face.el \
		lisp/php-face.elc \
		lisp/php-mode-debug.el \
		lisp/php-mode-debug.elc \
		lisp/php-mode.el \
		lisp/php-mode.elc \
		lisp/php-project.el \
		lisp/php-project.elc \
		lisp/php.el \
		lisp/php.elc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${LISP_FILES:C/^/${WRKSRC}\//g} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
