PORTNAME=	validate_url
PORTVERSION=	1.0.15
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Validating urls in Rails
WWW=		https://github.com/perfectline/validates_url/tree/master

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activemodel-gitlab>=3.0:databases/rubygem-activemodel-gitlab \
		rubygem-public_suffix>=0:dns/rubygem-public_suffix

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
