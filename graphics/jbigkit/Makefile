# New ports collection makefile for:	jbig
# Date created:		19 November 1996
# Whom:			mi
#
# $FreeBSD$
#

PORTNAME=	jbigkit
PORTVERSION=	1.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/download/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Lossless compression for bi-level images such as scanned pages, faxes

WRKSRC=	${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes

MAN1=	jbgtopbm.1 pbmtojbg.1

DOCSDIR?=	${PREFIX}/share/doc/jbig

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.doc ${DOCSDIR}
.endif

post-build test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} LD_LIBRARY_PATH=${WRKSRC}/libjbig ${MAKE} test

.include <bsd.port.mk>
