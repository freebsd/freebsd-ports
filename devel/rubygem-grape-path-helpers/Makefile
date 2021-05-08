PORTNAME=	grape-path-helpers
PORTVERSION=	1.6.3
PORTREVISION=	0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Route path helpers for Grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport60>=0:devel/rubygem-activesupport60 \
		rubygem-grape>=1.3<2:devel/rubygem-grape \
		rubygem-rake>=12:devel/rubygem-rake \
		rubygem-ruby2_keywords>=0.0.2<0.1:devel/rubygem-ruby2_keywords

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
