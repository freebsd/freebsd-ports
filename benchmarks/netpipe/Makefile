# New ports collection makefile for: netpipe
# Date created:		20 Feb 1998
# Whom:			jkoshy
#
# $FreeBSD$

PORTNAME=	NetPIPE
PORTVERSION=	3.6
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.scl.ameslab.gov/Projects/Netpipe/code/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A self-scaling network benchmark

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile

# The default port builds and installs only the TCP version of
# netpipe(1).  The sources support many other variants.

ALL_TARGET=	tcp
DOCS=		README netpipe_paper.ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/NPtcp ${PREFIX}/bin/NPtcp
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/netpipe
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/dox/${doc} ${PREFIX}/share/doc/netpipe/${doc}
.endfor
.endif

.include <bsd.port.mk>
