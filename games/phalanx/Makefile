# New ports collection makefile for:	phalanx
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	phalanx
PORTVERSION=	22
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.math.muni.cz/pub/math/people/Dobes/ \
		http://dusan.freeshell.org/phalanx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xboard-compatible chess playing program

WRKSRC=		${WRKDIR}/Phalanx-XXII

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} ${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	# empty
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/phalanx ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pbook.phalanx ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sbook.phalanx ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
