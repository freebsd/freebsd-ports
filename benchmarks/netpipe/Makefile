# New ports collection makefile for: netpipe
# Date created:		20 Feb 1998
# Whom:			jkoshy
#
# $FreeBSD$

PORTNAME=	NetPIPE
PORTVERSION=	3.6.2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.scl.ameslab.gov/Projects/Netpipe/code/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A self-scaling network benchmark

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile

# The default port builds and installs only the TCP version of
# netpipe(1).  The sources support many other variants.

ALL_TARGET=	tcp tcp6
.if !defined(NOPORTDOCS)
MAN1=		netpipe.1
MANCOMPRESSED=	no
DOCS=		README netpipe_paper.ps
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp ${PREFIX}/bin/NPtcp
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp6 ${PREFIX}/bin/NPtcp6
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/netpipe
	${INSTALL_MAN} ${WRKSRC}/dox/netpipe.1 ${PREFIX}/man/man1
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/dox/${doc} ${PREFIX}/share/doc/netpipe/${doc}
.endfor
.endif

.include <bsd.port.mk>
