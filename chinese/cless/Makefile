# New ports collection makefile for:    cless
# Version required:     2.90
# Date created:         Sat Aug 10, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.3 1996/11/12 02:16:34 obrien Exp $
#

DISTNAME=	cless-290
PKGNAME=	cn-${DISTNAME}
CATEGORIES=	chinese misc
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/c-utils/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/c-utils/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/c-utils/  \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/unix/c-utils/

MAINTAINER=     obrien@cs.ucdavis.edu

GNU_CONFIGURE=	yes
CFLAGS+=	-DHANZI # LDFLAGS=-s datadir=/usr/local/lib/less
MAN1=		cless.1 clesskey.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} -p ${PREFIX}/share/doc/cless
	${INSTALL_DATA} ${WRKSRC}/README.CLESS ${PREFIX}/share/doc/cless
.endif

.include <bsd.port.mk>
