# New ports collection makefile for:	jbig
# Version required:     0.9
# Date created:		19 November 1996
# Whom:			mi
#
# $Id: Makefile,v 1.2 1996/12/24 07:35:26 asami Exp $
#

DISTNAME=	jbigkit-0.9
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.informatik.uni-erlangen.de/pub/doc/ISO/JBIG/

MAINTAINER=	mi@aldan.ziplink.net

# Yes, CCFLAGS, not CFLAGS! -mi
MAKE_FLAGS=	CCFLAGS="${CFLAGS}" CC="${CC}"
WRKSRC= ${WRKDIR}/jbigkit
MAN1=	jbgtopbm.1 pbmtojbg.1
MAN5=	pbm.5

post-build:
	cd $(WRKSRC); make test

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jbig
	${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.doc ${PREFIX}/share/doc/jbig
.endif
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
