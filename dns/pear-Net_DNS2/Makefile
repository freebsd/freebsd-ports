PORTNAME=	Net_DNS2
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	dns net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP Resolver library used to communicate with a DNS server
WWW=		https://netdns2.com/ \
		https://github.com/mikepultz/netdns2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mikepultz
GH_PROJECT=	netdns2

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
