# New ports collection makefile for:	garith
# Date created:				5 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	garith
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cnm-vra.com/micah/garith/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arithmetic quiz program for X Window System

ALL_TARGET=	# empty
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
WRKSRC=		${WRKDIR}/garith

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garith ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/garith
.for file in BUGS COPYING HISTORY README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/garith
.endfor
.endif

.include <bsd.port.mk>
