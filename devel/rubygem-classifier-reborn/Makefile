# Created by: Michael Moll <kvedulv@kvedulv.de>

PORTNAME=	classifier-reborn
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classifier module for Bayesian and other types of classifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-fast-stemmer>=1.0<2:devel/rubygem-fast-stemmer \
		rubygem-matrix>=0.4<1:math/rubygem-matrix

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
