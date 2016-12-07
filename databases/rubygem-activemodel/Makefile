# $FreeBSD$

PORTNAME=	activemodel
PORTVERSION=	3.2.22.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:devel/rubygem-activesupport \
		rubygem-builder>=3.0.0:devel/rubygem-builder

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

DEPRECATED=	Upstream support ended
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
