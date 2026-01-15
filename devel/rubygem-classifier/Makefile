PORTNAME=	classifier
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classifier module for Bayesian and other types of classifications
WWW=		https://github.com/cardmagic/classifier

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-fast-stemmer>=1.0<2:devel/rubygem-fast-stemmer \
		rubygem-matrix>=0:math/rubygem-matrix \
		rubygem-mutex_m>=0.2<1:devel/rubygem-mutex_m \
		rubygem-rake>=0:devel/rubygem-rake

USES=		gem

.include <bsd.port.mk>
