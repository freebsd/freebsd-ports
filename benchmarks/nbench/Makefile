# New ports collection makefile for:	nbench
# Date created:				17 December 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	nbench
PORTVERSION=	2.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.tux.org/pub/tux/mayer/
MASTER_SITE_SUBDIR=	system/benchmark
DISTNAME=	${PORTNAME}-byte-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	BYTE Magazine\'s native benchmarks

ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbench ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/nbench
	${INSTALL_DATA} ${WRKSRC}/NNET.DAT ${PREFIX}/share/nbench
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/nbench
.for file in README README.submit RESULTS bdoc.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/nbench
.endfor
.endif

.include <bsd.port.mk>
