PORTNAME=	classifier
PORTVERSION=	1.4.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classifier module for Bayesian and other types of classifications
WWW=		https://github.com/cardmagic/classifier

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-fast-stemmer>=1.0<2:devel/rubygem-fast-stemmer \
		rubygem-mutex_m>=0.2<1:devel/rubygem-mutex_m \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
