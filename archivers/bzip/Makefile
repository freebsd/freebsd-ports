# New ports collection makefile for:    bzip
# Version required:     0.21
# Date created:         Fr  27 Sep 1996 11:47:35 MET DST
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.7 1996/11/18 11:15:27 asami Exp $
#

DISTNAME=       bzip-0.21
CATEGORIES=	archivers
MASTER_SITES=   http://www.cs.man.ac.uk/arch/people/j-seward/

MAINTAINER=     andreas@klemm.gtn.com

NO_CDROM=       yes     # Restrictive copyright (don't sell for profit)
MAN1=		bzip.1 bunzip.1

pre-install:
	@${CAT} ${FILESDIR}/COPYRIGHT

do-install:
	${RM} -f ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${PREFIX}/bin/bzip
	ln -fs ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${PREFIX}/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${PREFIX}/man/man1/bunzip.1

.include <bsd.port.mk>
