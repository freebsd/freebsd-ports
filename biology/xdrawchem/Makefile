# New ports collection makefile for:	xdrawchem
# Date created:				13 April 2000
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	xdrawchem
PORTVERSION=	0.99.7
CATEGORIES=	biology
MASTER_SITES=	http://www.prism.gatech.edu/~gte067k/xdrawchem/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

MAKE_ENV=	QTDIR="${X11BASE}"
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_QT_VER=	2
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

pre-build:
	cd ${WRKSRC}; \
		${CXX} ${CXXFLAGS} -O0 -c -DRINGHOME="\"${PREFIX}/share/xdrawchem/\"" -I${X11BASE}/include/qt2 -o molecule_tools.o molecule_tools.cpp

pre-install:
	${ECHO} bin/xdrawchem > ${PLIST}
	${LS} ${WRKSRC}/ring | \
		${SED} -e 's:^:share/xdrawchem/:' >> ${PLIST}
	${ECHO} @dirrm share/xdrawchem >> ${PLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${LS} *txt | \
		${SED} -e 's:^:share/doc/xdrawchem/:' >> ${PLIST}
	${ECHO} @dirrm share/doc/xdrawchem >> ${PLIST}
	${LS} ${WRKSRC}/save | \
		${SED} -e 's:^:share/examples/xdrawchem/:' >> ${PLIST}
	${ECHO} @dirrm share/examples/xdrawchem >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdrawchem ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ring/* ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/save/* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
