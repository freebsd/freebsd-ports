# $FreeBSD$

PORTNAME=	semantic_puppet
PORTVERSION=	0.1.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunnpoet@FreeBSD.org
COMMENT=	Library for working with Semantic Versions and module dependencies

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gettext-setup>=0.3:devel/rubygem-gettext-setup

DEPRECATED=	Use devel/rubygem-semantic_puppet instead
EXPIRATION_DATE=2017-07-31

PORTSCOUT=	limit:^0\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
