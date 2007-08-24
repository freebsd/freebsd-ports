# New ports collection makefile for:	libboard
# Date created:		Fri 24 aug 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		libboard
PORTVERSION=		0.8.0
CATEGORIES=		graphics
MASTER_SITES=		http://www.greyc.ensicaen.fr/~seb/board/download/

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		A vector graphics C++ library

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ENV=		CXX=${CXX}

USE_GMAKE=		yes
USE_LDCONFIG=		yes

PORTDOCS=	*

pre-configure:
	${REINPLACE_CMD} -e 's|-O3|${CXXFLAGS}|' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	${MV} ${PREFIX}/lib/libboard.so ${PREFIX}/lib/libboard.so.0
	${LN} -sf ${PREFIX}/lib/libboard.so.0 ${PREFIX}/lib/libboard.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

regression-test:
	(cd ${WRKDIR} && ${WRKSRC}/bin/arithmetic bec)
.for ex in 1 2 3
	(cd ${WRKDIR} && ${WRKSRC}/bin/example${ex})
.endfor
	${LS} -l ${WRKDIR}/arithm* ${WRKDIR}/draw*

.include <bsd.port.mk>
