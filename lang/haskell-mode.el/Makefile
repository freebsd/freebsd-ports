PORTNAME=	haskell-mode
DISTVERSIONPREFIX=	v
DISTVERSION=	17.5
PORTREVISION=	6
CATEGORIES=	lang elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp mode for editing haskell programs
WWW=		https://projects.haskell.org/haskellmode-emacs/

LICENSE=	GPLv3

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	haskell

#EMACS_FLAVORS_EXCLUDE=	devel_full devel_nox

ALL_TARGET=	haskell-mode-autoloads.el

NO_ARCH=	yes
SUB_FILES=	pkg-message

PLIST_DIRS=	share/emacs/site-lisp/${PORTNAME}/
PLIST_FILES=	${ELISPFILES:C/^| [^ ]/${PLIST_DIRS}/g}
PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${PREFIX}/${PLIST_DIRS}
ELISPFILES=	\
		ghc-core.el \
		ghci-script-mode.el \
		haskell-align-imports.el \
		haskell-c2hs.el \
		haskell-cabal.el \
		haskell-collapse.el \
		haskell-commands.el \
		haskell-compile.el \
		haskell-complete-module.el \
		haskell-completions.el \
		haskell-customize.el \
		haskell-debug.el \
		haskell-decl-scan.el \
		haskell-doc.el \
		haskell-font-lock.el \
		haskell-ghc-support.el \
		haskell-hoogle.el \
		haskell-indent.el \
		haskell-indentation.el \
		haskell-interactive-mode.el \
		haskell-lexeme.el \
		haskell-load.el \
		haskell-menu.el \
		haskell-mode-autoloads.el \
		haskell-mode.el \
		haskell-modules.el \
		haskell-move-nested.el \
		haskell-navigate-imports.el \
		haskell-presentation-mode.el \
		haskell-process.el \
		haskell-repl.el \
		haskell-sandbox.el \
		haskell-session.el \
		haskell-sort-imports.el \
		haskell-string.el \
		haskell-svg.el \
		haskell-unicode-input-method.el \
		haskell-utils.el \
		haskell.el \
		highlight-uses-mode.el \
		inf-haskell.el \
		w3m-haddock.el

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	${INSTALL_DATA} ${ELISPFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${ELISPDIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
