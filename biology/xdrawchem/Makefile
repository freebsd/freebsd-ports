# New ports collection makefile for:	xdrawchem
# Date created:				13 April 2000
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	xdrawchem
PORTVERSION=	0.84a
CATEGORIES=	biology
MASTER_SITES=	http://www.prism.gatech.edu/~gte067k/xdrawchem/
DISTNAME=	xdc084
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" QTDIR="${X11BASE}"
PLIST=		${WRKSRC}/pkg-plist
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_QT2=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

pre-install:
	${ECHO} bin/xdrawchem > ${PLIST}
	${ECHO} share/xdrawchem/calix4.ring >> ${PLIST}
	${ECHO} @dirrm share/xdrawchem >> ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdrawchem ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xdrawchem
	${INSTALL_DATA} ${WRKSRC}/ring/* ${PREFIX}/share/xdrawchem

.include <bsd.port.mk>
