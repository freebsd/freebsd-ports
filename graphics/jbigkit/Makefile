# Created by: mi
# $FreeBSD$

PORTNAME=	jbigkit
PORTVERSION=	1.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/download/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Lossless compression for bi-level images such as scanned pages, faxes

WRKSRC=	${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes

DOCSDIR?=	${PREFIX}/share/doc/jbig

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.doc ${STAGEDIR}${DOCSDIR}

post-build test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/libjbig ${MAKE} test

.include <bsd.port.mk>
