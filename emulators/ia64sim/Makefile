# ex:ts=8
# Ports collection makefile for:  ia64sim
# Date created:			  Tue Oct 10, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ia64sim
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.pacificsites.com/~ccrayne/  \
		http://www.glue.umd.edu/~jasonp/  \
		http://www.boo.net/~jasonp/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IA64 simulator (Intel(R) Architecture 64)

USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501103
BROKEN=		"does not build with latest gcc"
.endif

EXTRACT_BEFORE_ARGS=	-qLa
WRKSRC=		${WRKDIR}/home/chuck/ia64simcc
USE_GMAKE=	yes
MAKEFILE=	makefile.unx

pre-build:
	${RM} -f ${WRKSRC}/obj/*.o
	${RM} -f ${WRKSRC}/ia64sim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ia64user.txt ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
