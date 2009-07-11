# New ports collection makefile for:	nbench
# Date created:				17 December 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	nbench
PORTVERSION=	2.2.3
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.tux.org/~mayer/linux/
DISTNAME=	${PORTNAME}-byte-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BYTE Magazine's native benchmarks

ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/NNET.DAT ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README README.submit RESULTS bdoc.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
