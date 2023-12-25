PORTNAME=	Net_DNS2
PORTVERSION=	1.5.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	dns net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP Resolver library used to communicate with a DNS server
WWW=		https://pear.php.net/package/Net_DNS2 \
		https://github.com/mikepultz/netdns2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear

USE_GITHUB=	yes
GH_ACCOUNT=	mikepultz
GH_PROJECT=	netdns2

NO_ARCH=	yes

PLIST_FILES=	${PEARDIR}/Net/DNS2/Names.php \
		${PEARDIR}/Net/DNS2/RR/ZONEMD.php

post-install:
	${INSTALL_DATA} ${WRKSRC}/Net/DNS2/Names.php ${STAGEDIR}${PEARDIR}/Net/DNS2/Names.php
	${INSTALL_DATA} ${WRKSRC}/Net/DNS2/RR/ZONEMD.php ${STAGEDIR}${PEARDIR}/Net/DNS2/RR/ZONEMD.php

.include <bsd.port.mk>
