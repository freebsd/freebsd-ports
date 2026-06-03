PORTNAME=	mustermann-contrib
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add many plugins to Mustermann
WWW=		https://github.com/sinatra/mustermann/tree/main/mustermann-contrib \
		https://github.com/sinatra/mustermann

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-hansi>=0.2.0<0.3:devel/rubygem-hansi \
		rubygem-mustermann>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-mustermann

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
