# $FreeBSD$

PORTNAME=	rufus-scheduler
PORTVERSION=	3.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	342

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Ruby job scheduler for at, cron and others

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-et-orbi>=1.0:devel/rubygem-et-orbi

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PORTSCOUT=	limit:^3\.4\.2

.include <bsd.port.mk>
