# New ports collection makefile for:	jbig
# Version required:     1.0
# Date created:		19 November 1996
# Whom:			mi
#
# $FreeBSD$
#

DISTNAME=	jbigkit-1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.informatik.uni-erlangen.de/pub/doc/ISO/JBIG/

MAINTAINER=	mi@aldan.algebra.com

WRKSRC= ${WRKDIR}/jbigkit
MAN1=	jbgtopbm.1 pbmtojbg.1
MAN5=	pbm.5 pgm.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jbig
	${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.doc ${PREFIX}/share/doc/jbig
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
