# $FreeBSD$

PORTNAME=	pry-byebug
PORTVERSION=	3.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast debugging with Pry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-byebug>=10.0:devel/rubygem-byebug \
		rubygem-pry>=0.10:devel/rubygem-pry

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
