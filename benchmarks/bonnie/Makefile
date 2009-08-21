# New ports collection makefile for:    bonnie
# Date created:         26 September 1994
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	bonnie
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.acnc.com/benchmarks/ \
		http://www.textuality.com/bonnie/
DISTNAME=	bonnie

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O

NO_WRKSUBDIR=	yes
#CFLAGS+=	-static
MAKE_ARGS+=	-e CFLAGS="${CFLAGS}"
ALL_TARGET=	bsd
MAN1=		bonnie.1
PLIST_FILES=	bin/bonnie

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bonnie ${PREFIX}/bin/bonnie
	${INSTALL_MAN} ${FILESDIR}/bonnie.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
