# ex:ts=8
# Ports collection makefile for:    zmtx-zmrx
# Version required:     1.02
# Date created:         29 July 1996
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id: Makefile,v 1.4 1997/10/10 06:53:48 obrien Exp $
#

DISTNAME=	zmtx-zmrx
PKGNAME=	zmtx-zmrx-1.02
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.inria.fr/network/modem/  \
		ftp://ftp.vex.net/pub/software/
# see also comp.unix.sources for version 1.0
# ftp://ftp.lth.se/pub/usenet/comp.sources.unix/volume28/zm/part01.gz
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	obrien@FreeBSD.org

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
PKG_CMD=	/usr/sbin/pkg_create -D ${PKGDIR}/licence
MAN1=		zmrx.1 zmtx.1

do-install:
.for f in zmrx zmtx
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin 
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${PREFIX}/man/man1
.endfor

post-install:
	@${ECHO} ""
	@/usr/bin/more ${PKGDIR}/licence
	@${ECHO} ""

.include <bsd.port.mk>
