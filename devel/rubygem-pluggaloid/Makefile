# $FreeBSD$

PORTNAME=	pluggaloid
PORTVERSION=	1.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Extensible plugin system for mikutter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-delayer>=0:devel/rubygem-delayer \
		rubygem-instance_storage>=1.0.0<2:devel/rubygem-instance_storage

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
