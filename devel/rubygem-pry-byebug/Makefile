PORTNAME=	pry-byebug
PORTVERSION=	3.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast debugging with Pry
WWW=		https://github.com/deivid-rodriguez/pry-byebug

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-byebug>=11.0<12:devel/rubygem-byebug \
		rubygem-pry>=0.13<0.15:devel/rubygem-pry

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
