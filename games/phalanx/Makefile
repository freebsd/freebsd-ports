# New ports collection makefile for:	phalanx
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	phalanx
PORTVERSION=	22
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.math.muni.cz/pub/math/people/Dobes/ \
		http://dusan.freeshell.org/phalanx/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Xboard-compatible chess playing program

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/Phalanx-XXII
USE_GMAKE=	yes
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
