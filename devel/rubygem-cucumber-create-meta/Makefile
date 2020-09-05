# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-create-meta
PORTVERSION=	2.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Produce the meta message for Cucumber Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages>=13.0.1<14:devel/rubygem-cucumber-messages \
		rubygem-sys-uname>=1.2.1<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
