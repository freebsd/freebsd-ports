# New ports collection makefile for:    iozone
# Version required:     2.01
# Date created:         26 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.20 1999/02/03 11:11:39 asami Exp $
#

DISTNAME=       iozone
PKGNAME=	iozone-3.0
CATEGORIES=	benchmarks
MASTER_SITES=   http://www.iozone.org/src/
EXTRACT_SUFX=	.tar

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/src

MAKEFILE=	makefile
MAKE_ARGS=	freebsd
ALL_TARGET=

MAN1=		iozone.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iozone.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
