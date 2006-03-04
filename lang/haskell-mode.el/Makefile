# New ports collection makefile for:	haskell-mode.el
# Date created:		5 March 2004
# Whom:			Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	haskell-mode
PORTVERSION=	2.1
CATEGORIES=	lang elisp
MASTER_SITES=	http://www.iro.umontreal.ca/~monnier/elisp/ \
		http://macemacsjp.sourceforge.jp/package/20051117/GPL/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	An Emacs lisp mode for editing haskell programs

NO_BUILD=	yes

ELISPDIR=	${PREFIX}/${PLIST_DIRS}
ELISPFILES=	haskell-decl-scan.el haskell-doc.el haskell-font-lock.el \
		haskell-ghci.el haskell-hugs.el haskell-indent.el \
		haskell-mode.el haskell-simple-indent.el haskell-site-file.el \
		inf-haskell.el

PLIST_DIRS=	share/emacs/site-lisp/${PORTNAME}/
PLIST_FILES=	${ELISPFILES:C/^| [^ ]/${PLIST_DIRS}/g}

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog NEWS fontlock.hs indent.hs \
		index.html installation-guide.html
.endif

do-install:
	${MKDIR} ${ELISPDIR}
.for i in ${ELISPFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${ELISPDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
