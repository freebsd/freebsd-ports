# New ports collection makefile for:	phalanx
# Version required:			21
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		phalanx-21
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://ftp.math.muni.cz/pub/math/people/Dobes/
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=			${WRKDIR}/Phalanx-XXI
USE_GMAKE=		yes
ALL_TARGET=
MAKEFILE=		makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/phalanx ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/phalanx
	@ ${INSTALL_DATA} ${WRKSRC}/pbook.phalanx ${PREFIX}/share/phalanx
	@ ${INSTALL_DATA} ${WRKSRC}/sbook.phalanx ${PREFIX}/share/phalanx

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/phalanx
	@ ${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/phalanx
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/phalanx
.endif

.include <bsd.port.mk>
