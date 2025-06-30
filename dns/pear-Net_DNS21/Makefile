PORTNAME=	Net_DNS2
PORTVERSION=	1.5.5
DISTVERSIONPREFIX=	v
CATEGORIES=	dns net pear
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP Resolver library used to communicate with a DNS server
WWW=		https://pear.php.net/package/Net_DNS2 \
		https://github.com/mikepultz/netdns2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mikepultz
GH_PROJECT=	netdns2

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
