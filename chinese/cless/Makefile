# New ports collection makefile for:    cless
# Version required:     2.90
# Date created:         Sat Aug 10, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/08/09 04:17:16 asami Exp $
#

DISTNAME=	cless-290
CATEGORIES+=	chinese misc
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/c-utils/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/c-utils/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/c-utils/  \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/unix/c-utils/

MAINTAINER=     obrien@cs.ucdavis.edu

GNU_CONFIGURE=	yes
CFLAGS+=	-DHANZI # LDFLAGS=-s datadir=/usr/local/lib/less

post-install:
.if !defined(NOMANCOMPRESS)
.for mp in cless clesskey
	gzip -9nf ${PREFIX}/man/man1/${mp}.1
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} -p ${PREFIX}/share/doc/cless
	${INSTALL_DATA} ${WRKSRC}/README.CLESS ${PREFIX}/share/doc/cless
.endif

.include <bsd.port.mk>
