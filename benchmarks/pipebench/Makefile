# ex:ts=8
# New ports collection makefile for:	pipebench
# Date created:			Jan 14, 2003
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	pipebench
PORTVERSION=	0.40
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Pipebench shows current throughput/amount of data through a pipe

CFLAGS+=	-w -pedantic

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pipebench.1 ${PREFIX}/man/man1

MAN1=		pipebench.1
PLIST_FILES=	bin/pipebench

.include <bsd.port.mk>
