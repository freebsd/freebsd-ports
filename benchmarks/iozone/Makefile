# New ports collection makefile for:    iozone
# Date created:         26 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	iozone
PORTVERSION=	3.137
PORTREVISION=	0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.iozone.org/src/current/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tar

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/src/current

MAKEFILE=	makefile
MAKE_ARGS=	freebsd
ALL_TARGET=

MAN1=		iozone.1

do-install:
	strip ${WRKSRC}/iozone
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/docs/iozone.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
