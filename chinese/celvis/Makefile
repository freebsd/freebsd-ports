# New ports collection makefile for:    celvis
# Version required:     1.3
# Date created:         Thur Aug 15, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.2 1996/10/16 02:24:33 chuckr Exp $
#

DISTNAME=	celvis
PKGNAME=	cn-celvis-1.3
CATEGORIES=	chinese editors
MASTER_SITES=	ftp://ftp.cs.purdue.edu/pub/ygz/  \
		ftp://ftp.ifcss.org/pub/software/x-win/cxterm/

MAINTAINER=     obrien@cs.ucdavis.edu

do-install:
	@# install target in celvis Makefile is not too good -- this is easier
	${INSTALL_PROGRAM} ${WRKSRC}/celvis ${WRKSRC}/virec ${PREFIX}/bin
	ln -sf ${PREFIX}/bin/celvis ${PREFIX}/bin/cvi
	${INSTALL_MAN} ${FILESDIR}/celvis.1 ${PREFIX}/man/man1/celvis.1
.if !defined{NOMANCOMPRESS}
	gzip -9nf ${PREFIX}/man/man1/celvis.1
	ln -sf ${PREFIX}/man/man1/celvis.1.gz ${PREFIX}/man/man1/cvi.1.gz
.else
	ln -sf ${PREFIX}/man/man1/celvis.1 ${PREFIX}/man/man1/cvi.1
.endif

.include <bsd.port.mk>
