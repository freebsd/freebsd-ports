# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnscap
DISTVERSION=	134
CATEGORIES=	dns
MASTER_SITES=	http://dnscap.dns-oarc.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DNS network traffic capture utility

LICENSE=	ISCL

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dnscap man/man1/dnscap.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnscap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnscap.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
