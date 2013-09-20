# Created by: Josh Elsasser <jre@vineyard.net>
# $FreeBSD$

PORTNAME=	haskell-mode
PORTVERSION=	2.9.1
CATEGORIES=	lang elisp

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Emacs lisp mode for editing haskell programs

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

GH_ACCOUNT=	haskell
GH_COMMIT=	166ec39
GH_TAGNAME=	${PORTVERSION:S/./_/g}
NO_BUILD=	yes
PORTDOCS=	NEWS fontlock.hs indent.hs README.md
USE_GITHUB=	yes

ELISPDIR=	${PREFIX}/${PLIST_DIRS}
ELISPFILES=	ghc-core.el haskell-align-imports.el haskell-c.el \
		haskell-cabal.el haskell-checkers.el haskell-decl-scan.el \
		haskell-doc.el haskell-font-lock.el haskell-ghci.el \
		haskell-hugs.el haskell-indent.el haskell-indentation.el \
		haskell-interactive-mode.el haskell-mode.el \
		haskell-move-nested.el  haskell-navigate-imports.el \
		haskell-package.el haskell-process.el haskell-session.el \
		haskell-show.el haskell-simple-indent.el haskell-site-file.el \
		haskell-sort-imports.el haskell-string.el inf-haskell.el

PLIST_DIRS=	share/emacs/site-lisp/${PORTNAME}/
PLIST_FILES=	${ELISPFILES:C/^| [^ ]/${PLIST_DIRS}/g}
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>
do-install:
	@${MKDIR} ${ELISPDIR}
	@${INSTALL_DATA} ${ELISPFILES:S,^,${WRKSRC}/,} ${ELISPDIR}/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
