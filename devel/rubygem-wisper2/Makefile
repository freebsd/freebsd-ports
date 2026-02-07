PORTNAME=	wisper
PORTVERSION=	2.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Library for Ruby objects with Publish-Subscribe capabilities
WWW=		https://github.com/krisleech/wisper

LICENSE=	MIT

USES=		gem

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/console ${STAGEDIR}${PREFIX}/bin/setup

.include <bsd.port.mk>
