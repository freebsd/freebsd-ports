# ex:ts=8
# Ports collection makefile for:  zmtx-zmrx
# Date created:			  29 July 1996
# Whom:				  David O'Brien <obrien@cs.ucdavis.edu>
#
# $FreeBSD$
#

PORTNAME=	zmtx-zmrx
PORTVERSION=	1.02
CATEGORIES=	comms
# previous mastersites disappeared in May 2003.  See, perhaps,
# cvs.synchro.net/cgi-bin/viewcvs/src/stp, as a possible followon
# project.
MASTER_SITES=	# ftp://ftp.inria.fr/network/modem/
# see also comp.unix.sources for version 1.0
# ftp://ftp.lth.se/pub/usenet/comp.sources.unix/volume28/zm/part01.gz
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Receive/Send files via ZMODEM protocol.  (unrestrictive)

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		zmrx.1 zmtx.1

do-install:
.for f in zmrx zmtx
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${PREFIX}/man/man1
.endfor

post-install:
	@${ECHO_MSG} ""
	@/usr/bin/more ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
