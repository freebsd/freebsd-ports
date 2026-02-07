PORTNAME=	php-mode.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.27.0
PORTREVISION=	1
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	marc@bumblingdork.com
COMMENT=	PHP mode for GNU Emacs
WWW=		https://github.com/emacs-php/php-mode

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	emacs-php
GH_PROJECT=	${PORTNAME:S/.el$//}

EMACS_FLAVORS_EXCLUDE=	devel_full devel_nox # Eager macro-expansion failure: (void-variable flymake-allowed-file-name-masks)

NO_ARCH=	yes

LISP_FILES=	lisp/php-align.el \
		lisp/php-align.elc \
		lisp/php-complete.el \
		lisp/php-complete.elc \
		lisp/php-defs.el \
		lisp/php-defs.elc \
		lisp/php-face.el \
		lisp/php-face.elc \
		lisp/php-flymake.el \
		lisp/php-flymake.elc \
		lisp/php-format.el \
		lisp/php-format.elc \
		lisp/php-ide-phpactor.el \
		lisp/php-ide-phpactor.elc \
		lisp/php-ide.el \
		lisp/php-ide.elc \
		lisp/php-local-manual.el \
		lisp/php-local-manual.elc \
		lisp/php-mode-debug.el \
		lisp/php-mode-debug.elc \
		lisp/php-mode.el \
		lisp/php-mode.elc \
		lisp/php-project.el \
		lisp/php-project.elc \
		lisp/php.el \
		lisp/php.elc

do-build:
	${EMACS_CMD} -q --batch -L ${WRKSRC}/lisp/ -f batch-byte-compile ${WRKSRC}/lisp/*.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${LISP_FILES:C/^/${WRKSRC}\//g} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
