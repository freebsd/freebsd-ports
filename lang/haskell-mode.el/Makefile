# New ports collection makefile for:	haskell-mode.el
# Date created:		5 March 2004
# Whom:			Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	haskell-mode
PORTVERSION=	1.44
CATEGORIES=	lang elisp
MASTER_SITES=	http://www.haskell.org/haskell-mode/

MAINTAINER=	jre@vineyard.net
COMMENT=	An Emacs lisp mode for editing haskell programs

NO_BUILD=	yes

ELISPDIR=	${PREFIX}/${PLIST_DIRS}
ELISPFILES=	haskell-decl-scan.el haskell-doc.el haskell-font-lock.el \
		haskell-ghci.el haskell-hugs.el haskell-indent.el \
		haskell-mode.el haskell-simple-indent.el

PLIST_DIRS=	share/emacs/site-lisp/${PORTNAME}/
PLIST_FILES=	${ELISPFILES:C/^| [^ ]/${PLIST_DIRS}/g}

do-install:
	${MKDIR} ${ELISPDIR}
.for i in ${ELISPFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${ELISPDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
