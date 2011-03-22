#
# Ports collection makefile for:	dns/dnscap
# Whom:					Edwin Groothuis <edwin@mavetju.org>
# Date created:				2008-09-17
#
# $FreeBSD$

PORTNAME=	dnscap
DISTVERSION=	134
CATEGORIES=	dns
MASTER_SITES=	http://dnscap.dns-oarc.net/

MAINTAINER=	edwin@mavetju.org
COMMENT=	DNS network traffic capture utility

HAS_CONFIGURE=	yes

MAN1=		dnscap.1
PLIST_FILES=	bin/dnscap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnscap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnscap.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
