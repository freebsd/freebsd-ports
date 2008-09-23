#
# Ports collection makefile for:	dns/dnscap
# Whom:					Edwin Groothuis <edwin@mavetju.org>
# Date created:				2008-09-17
#
# $FreeBSD$

PORTNAME=	dnscap
DISTVERSION=	1.0-RC6
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.mavetju.org/download/adopted/

MAINTAINER=	edwin@mavetju.org
COMMENT=	DNS network traffic capture utility

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/dnscap/

MAN1=		dnscap.1
PLIST_FILES=	bin/dnscap

post-extract:
	${MKDIR} ${WRKSRC}/isc
	${CP} ${FILESDIR}/*.h ${WRKSRC}/isc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnscap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnscap.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
