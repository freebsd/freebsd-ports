# New ports collection makefile for:	gramofile
# Date created:		Fri Jan 28 18:40:38 CET 2000
# Whom:			nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

PORTNAME=	gramofile
PORTVERSION=	1.6
CATEGORIES=	audio
MASTER_SITES=	http://panic.et.tudelft.nl/~costar/gramofile/

MAINTAINER=	nox@jelal.kn-bremen.de

ALL_TARGET=	gramofile
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gramofile ${WRKSRC}/bplay_gramo ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/gramofile
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gramofile
	${LN} -s bplay_gramo ${PREFIX}/bin/brec_gramo

.include <bsd.port.mk>
