PORTNAME=	spring-watcher-listen
PORTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Makes spring watch files using the listen gem
WWW=		https://github.com/jonleighton/spring-watcher-listen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-listen>=2.7<4.0:devel/rubygem-listen \
		rubygem-spring>=4:devel/rubygem-spring

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
