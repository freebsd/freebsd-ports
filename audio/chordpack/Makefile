# New ports collection makefile for:	chordpack
# Date created:		July 8, 2001
# Whom:			sethk
#
# $FreeBSD$
#

PORTNAME=	chordpack
PORTVERSION=	0.8.0
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
	[ -d ${PREFIX}/share/doc/chordpack ] ||	\
		${MKDIR} ${PREFIX}/share/doc/chordpack
	${INSTALL_MAN} ${WRKDIR}/chordpack-documentation.html	\
		${PREFIX}/share/doc/chordpack

.include <bsd.port.mk>
