# New ports collection makefile for:    bonnie
# Version required:     1.0
# Date created:         26 September 1994
# Whom:                 se
#
# $FreeBSD$
#

DISTNAME=       Bonnie
PKGNAME=	bonnie-1.0
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.sunet.se/pub/benchmark/Bonnie/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	se@FreeBSD.org

MAN1=		bonnie.1

CFLAGS+=	-static
MAKE_ARGS+=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bonnie ${PREFIX}/bin/bonnie
	${INSTALL_DATA} ${WRKSRC}/bonnie.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
