# New ports collection makefile for: netpipe
# Version required: 	2.3
# Date created:		20 Feb 1998
# Whom:			jkoshy
#
# $Id$

DISTNAME=	netpipe-2.3
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.ameslab.gov/pub/netpipe/ \
		http://www.freebsd.org/~jkoshy/PORTS/

MAINTAINER=	jkoshy@freebsd.org

# The default port builds and installs only the TCP version of
# netpipe(1).  The sources also support PVM and MPI.

ALL_TARGET=	NPtcp
MAN1=		netpipe.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp ${PREFIX}/bin/NPtcp
	${INSTALL_DATA} ${WRKSRC}/netpipe.1 ${PREFIX}/man/man1/netpipe.1

.include <bsd.port.mk>
