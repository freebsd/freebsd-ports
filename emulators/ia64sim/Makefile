# Ports collection makefile for:  ia64sim
# Date created:			  Tue Oct 10, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ia64sim
PORTVERSION=	0.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.glue.umd.edu/~jasonp/  \
		http://odin.asgard/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

EXTRACT_BEFORE_ARGS=	-qLa
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.unx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${LOCALBASE}/bin/ia64sim
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ia64sim
	${INSTALL_DATA} ${WRKDIR}/ia64.doc ${PREFIX}/share/doc/ia64sim
.endif

.include <bsd.port.mk>
