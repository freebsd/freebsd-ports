# ex:ts=8
# Ports collection makefile for:  ia64sim
# Date created:			  Tue Oct 10, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ia64sim
PORTVERSION=	0.5
CATEGORIES=	emulators
MASTER_SITES=	http://www.pacificsites.com/~ccrayne/  \
		http://www.glue.umd.edu/~jasonp/  \
		http://odin.asgard/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

EXTRACT_BEFORE_ARGS=	-qLa
WRKSRC=		${WRKDIR}/home/chuck/ia64simcc
USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.unx

pre-build:
	rm -f ${WRKSRC}/obj/*.o
	rm -f ${WRKSRC}/ia64sim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ia64user.txt ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
