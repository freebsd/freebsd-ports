# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cucumber-create-meta
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Produce the meta message for Cucumber Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages>=15.0.0<16:devel/rubygem-cucumber-messages \
		rubygem-sys-uname>=1.2.2<2:sysutils/rubygem-sys-uname

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
