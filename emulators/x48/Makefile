# New ports collection makefile for:    x48
# Date created:         Thu Oct 24 13:10:59 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.4.1d
CATEGORIES=	emulators
MASTER_SITES=	http://home.earthlink.net/~rmmlgetz/
DISTNAME=	${PORTNAME}_041d

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes


WRKSRC=		${WRKDIR}/x48-0.4.1

post-extract:
	cd ${WRKSRC}/readline && ${RM} *.o

post-install:
	${MKDIR} ${PREFIX}/share/x48
	${CP} ${WRKSRC}/README ${PREFIX}/share/x48/README-x48
	${CP} ${WRKSRC}/doc/CARDS.doc ${WRKSRC}/doc/ROMDump.doc ${PREFIX}/share/x48

.include <bsd.port.mk>
