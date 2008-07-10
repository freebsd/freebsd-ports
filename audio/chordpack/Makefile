# New ports collection makefile for:	chordpack
# Date created:		July 8, 2001
# Whom:			sethk
#
# $FreeBSD$
#

PORTNAME=	chordpack
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://sweb.cz/dan.polansky/chordpack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Script to convert ChordPro files to HTML, ASCII, and TeX

NO_WRKSUBDIR=	true
NO_BUILD=	true

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/chordpack ${PREFIX}/bin
	[ -d ${PREFIX}/share/emacs/site-lisp ] ||   \
		${MKDIR} ${MKDIR}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKDIR}/chordpro-mode.el  \
		${PREFIX}/share/emacs/site-lisp
.ifndef(NOPORTDOCS)
	[ -d ${PREFIX}/share/doc/chordpack ] ||	\
		${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/chordpack-documentation.html	\
		${DOCSDIR}
.endif

.include <bsd.port.mk>
