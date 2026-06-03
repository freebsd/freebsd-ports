PORTNAME=	php-mode.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.27.0
PORTREVISION=	2
CATEGORIES=	lang elisp

MAINTAINER=	marc@bumblingdork.com
COMMENT=	PHP mode for GNU Emacs
WWW=		https://github.com/emacs-php/php-mode

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-php
GH_PROJECT=	${PORTNAME:S/.el$//}

CONFLICTS_INSTALL=	php-mode.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

LISP_FILES=	lisp/php-align.el \
		lisp/php-complete.el \
		lisp/php-defs.el \
		lisp/php-face.el \
		lisp/php-flymake.el \
		lisp/php-format.el \
		lisp/php-ide-phpactor.el \
		lisp/php-ide.el \
		lisp/php-local-manual.el \
		lisp/php-mode-debug.el \
		lisp/php-mode.el \
		lisp/php-project.el \
		lisp/php.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${LISP_FILES:C/^/${WRKSRC}\//g} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
