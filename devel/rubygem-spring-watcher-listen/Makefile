PORTNAME=	spring-watcher-listen
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Makes spring watch files using the listen gem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-listen>=2.7<4.0:devel/rubygem-listen \
		rubygem-spring>=1.2:devel/rubygem-spring

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
