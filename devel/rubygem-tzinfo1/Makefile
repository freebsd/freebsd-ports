# Created by: Rui Lopes (rgl ruilopes com)
# $FreeBSD$

PORTNAME=	tzinfo
PORTVERSION=	1.2.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Daylight-savings aware timezone support for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-thread_safe>=0.1<1:devel/rubygem-thread_safe

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
