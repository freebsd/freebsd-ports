# New ports collection makefile for:	haskell-mode.el
# Date created:		5 March 2004
# Whom:			Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	haskell-mode
PORTVERSION=	2.4
CATEGORIES=	lang elisp
MASTER_SITES=	http://www.iro.umontreal.ca/~monnier/elisp/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	An Emacs lisp mode for editing haskell programs

NO_BUILD=	yes

PORTDOCS=	ChangeLog NEWS fontlock.hs indent.hs README

ELISPDIR=	${PREFIX}/${PLIST_DIRS}
ELISPFILES=	haskell-c.el haskell-cabal.el haskell-decl-scan.el \
		haskell-doc.el haskell-font-lock.el haskell-ghci.el \
		haskell-hugs.el haskell-indent.el haskell-mode.el \
		haskell-simple-indent.el haskell-site-file.el inf-haskell.el

PLIST_DIRS=	share/emacs/site-lisp/${PORTNAME}/
PLIST_FILES=	${ELISPFILES:C/^| [^ ]/${PLIST_DIRS}/g}

do-install:
	@${MKDIR} ${ELISPDIR}
	@${INSTALL_DATA} ${ELISPFILES:S,^,${WRKSRC}/,} ${ELISPDIR}/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
