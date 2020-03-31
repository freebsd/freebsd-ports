# $FreeBSD$

PORTNAME=	pry-byebug
PORTVERSION=	3.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast debugging with Pry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-byebug>=11.0<12:devel/rubygem-byebug \
		rubygem-pry>=0.13.0<0.14:devel/rubygem-pry

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
