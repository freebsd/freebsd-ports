# New ports collection makefile for:    bzip
# Version required:     0.21
# Date created:         Fr  27 Sep 1996 11:47:35 MET DST
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1996/10/19 09:12:02 andreas Exp $
#

DISTNAME=       bzip-0.21
CATEGORIES=	archivers
MASTER_SITES=   http://www.cs.man.ac.uk/arch/people/j-seward/

MAINTAINER=     andreas@klemm.gtn.com

NO_CDROM=       yes     # Restrictive copyright (don't sell for profit)

pre-install:
	@${CAT} ${FILESDIR}/COPYRIGHT

do-install:
	rm -f ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${PREFIX}/bin/bzip
	ln -s ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${PREFIX}/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${PREFIX}/man/man1/bunzip.1
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/bzip.1
	gzip -9nf ${PREFIX}/man/man1/bunzip.1
.endif

.include <bsd.port.mk>
