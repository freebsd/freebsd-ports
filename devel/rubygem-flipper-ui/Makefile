PORTNAME=	flipper-ui
PORTVERSION=	1.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Feature flag UI for the Flipper gem
WWW=		https://www.flippercloud.io/ \
		https://github.com/flippercloud/flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubi>=1.0.0<2.0.0:www/rubygem-erubi \
		rubygem-flipper>=${PORTVERSION}<1.3:devel/rubygem-flipper \
		rubygem-rack>=1.4,3<4,3:www/rubygem-rack \
		rubygem-rack-protection>=1.5.3<4.0.0_99:www/rubygem-rack-protection \
		rubygem-sanitize>=0<7:textproc/rubygem-sanitize

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
