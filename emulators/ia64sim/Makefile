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

MAINTAINER=	obrien@FreeBSD.org

EXTRACT_BEFORE_ARGS=	-qLa
WRKSRC=		${WRKDIR}/home/chuck/ia64simcc
USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.unx

pre-build:
	rm -f ${WRKSRC}/obj/*.o
	rm -f ${WRKSRC}/ia64sim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ia64sim
	${INSTALL_DATA} ${WRKDIR}/ia64.doc ${PREFIX}/share/doc/ia64sim
.endif

.include <bsd.port.mk>
