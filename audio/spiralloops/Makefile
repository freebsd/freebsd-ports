# New ports collection makefile for:	spiralloops
# Date created:				2000-12-06
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	spiralloops
PORTVERSION=	0.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.pawfal.org/SpiralLoops/dload/
DISTNAME=	SpiralLoops-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

DOCDIR=		share/doc/${PORTNAME}
DOC_FILES=	CHANGES COPYING README
GNU_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

pre-patch:
	${PERL} -pi -e "s:-ldl::g" ${WRKSRC}/Makefile.in

pre-install:
	${ECHO} bin/SpiralLoops > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOC_FILES}
	${ECHO} ${DOCDIR}/`${BASENAME} ${i}` >> ${PLIST}
.endfor
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif
.include <bsd.port.mk>
