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
		http://www.crosswinds.net/~dobes/phalanx/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/Phalanx-XXII
USE_GMAKE=	yes
ALL_TARGET=	# empty
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/phalanx ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/phalanx
	${INSTALL_DATA} ${WRKSRC}/pbook.phalanx ${PREFIX}/share/phalanx
	${INSTALL_DATA} ${WRKSRC}/sbook.phalanx ${PREFIX}/share/phalanx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/phalanx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/phalanx
.endif

.include <bsd.port.mk>
