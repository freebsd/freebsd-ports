PORTNAME=	pry-byebug
PORTVERSION=	3.11.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast debugging with Pry
WWW=		https://github.com/deivid-rodriguez/pry-byebug

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-byebug>=12.0<13:devel/rubygem-byebug \
		rubygem-pry>=0.13<0.17:devel/rubygem-pry

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
