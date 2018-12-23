# $FreeBSD$

PORTNAME=	peek-rblineprof
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Peek into how much each line of your Rails application takes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-peek-rails50>=0:devel/rubygem-peek-rails50 \
		rubygem-rblineprof>=0:devel/rubygem-rblineprof

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
