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

INSTALLS_SHLIB=	yes

MAN1=	jbgtopbm.1 pbmtojbg.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jbig
	${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.doc ${PREFIX}/share/doc/jbig
.endif

post-build test:
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC}/libjbig ${MAKE} test

.include <bsd.port.mk>
