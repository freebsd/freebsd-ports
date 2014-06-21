# Created by: mi
# $FreeBSD$

PORTNAME=	jbigkit
PORTVERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/download/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Lossless compression for bi-level images such as scanned pages, faxes

USE_LDCONFIG=	yes
MAN1=	jbgtopbm.1 pbmtojbg.1
BINS=	jbgtopbm pbmtojbg jbgtopbm85 pbmtojbg85
LIBS=	libjbig.a libjbig.so.2 libjbig85.a libjbig85.so.1
DOCSDIR?=	${PREFIX}/share/doc/jbig

do-install:
	${INSTALL_PROGRAM}	\
		${BINS:S|^|${WRKSRC}/pbmtools/|} ${STAGEDIR}${PREFIX}/bin

	${INSTALL_MAN}	\
		${MAN1:S|^|${WRKSRC}/pbmtools/|} ${STAGEDIR}${MANPREFIX}/man/man1

	${INSTALL_DATA} ${WRKSRC}/libjbig/*.h ${STAGEDIR}${PREFIX}/include

	${INSTALL_DATA}	\
		${LIBS:S|^|${WRKSRC}/libjbig/|} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libjbig.so.1 ${STAGEDIR}${PREFIX}/lib/libjbig.so
	${LN} -sf libjbig85.so.1 ${STAGEDIR}${PREFIX}/lib/libjbig85.so

.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.txt ${STAGEDIR}${DOCSDIR}
.endif

regression-test test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/libjbig ${MAKE} test

.include <bsd.port.mk>
