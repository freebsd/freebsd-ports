# New ports collection makefile for:    iozone
# Version required:     3.9
# Date created:         26 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	iozone3_9
PKGNAME=	iozone-3.9
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/stable/
EXTRACT_SUFX=	.tar

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/src

MAKEFILE=	makefile
MAKE_ARGS=	freebsd
ALL_TARGET=

MAN1=		iozone.1

do-install:
	strip ${WRKSRC}/iozone
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iozone.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
