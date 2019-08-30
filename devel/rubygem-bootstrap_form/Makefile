# $FreeBSD$

PORTNAME=	bootstrap_form
PORTVERSION=	4.2.0
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Form builder using Twitter Bootstrap 3+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionpack52>=5.0:www/rubygem-actionpack52 \
		rubygem-activemodel52>=5.0:databases/rubygem-activemodel52

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
