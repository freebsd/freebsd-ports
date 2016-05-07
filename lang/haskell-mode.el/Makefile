# Created by: Josh Elsasser <jre@vineyard.net>
# $FreeBSD$

PORTNAME=	haskell-mode
PORTVERSION=	13.20
DISTVERSIONPREFIX=v
CATEGORIES=	lang elisp

MAINTAINER=	aehlig@linta.de
COMMENT=	Emacs lisp mode for editing haskell programs

LICENSE=	GPLv3

USE_EMACS=	yes

OPTIONS_DEFINE=	DOCS

GH_ACCOUNT=	haskell
PORTDOCS=	NEWS README.md
USE_GITHUB=	yes
USES=		gmake
ALL_TARGET=	haskell-mode-autoloads.el

ELISPDIR=	${PREFIX}/${PLIST_DIRS}
ELISPFILES=	ghc-core.el ghci-script-mode.el haskell-align-imports.el \
		haskell-c2hs.el \
		haskell-cabal.el haskell-checkers.el \
		haskell-collapse.el haskell-commands.el \
		haskell-compile.el haskell-compat.el \
		haskell-complete-module.el haskell-completions.el \
		haskell-customize.el \
		haskell-debug.el haskell-decl-scan.el \
		haskell-doc.el haskell-font-lock.el haskell-hoogle.el \
		haskell-indent.el haskell-indentation.el \
		haskell-interactive-mode.el haskell-lexeme.el haskell-load.el \
		haskell-menu.el haskell-mode-pkg.el haskell-mode.el \
		haskell-mode-autoloads.el haskell-modules.el \
		haskell-move-nested.el haskell-navigate-imports.el \
		haskell-presentation-mode.el \
		haskell-process.el haskell-repl.el haskell-sandbox.el \
		haskell-session.el \
		haskell-sort-imports.el haskell-string.el \
		haskell-unicode-input-method.el haskell-utils.el \
		haskell.el highlight-uses-mode.el inf-haskell.el \
		w3m-haddock.el

PLIST_DIRS=	share/emacs/site-lisp/${PORTNAME}/
PLIST_FILES=	${ELISPFILES:C/^| [^ ]/${PLIST_DIRS}/g}
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	${INSTALL_DATA} ${ELISPFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${ELISPDIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
