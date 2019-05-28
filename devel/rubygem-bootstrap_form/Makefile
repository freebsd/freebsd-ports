# $FreeBSD$

PORTNAME=	bootstrap_form
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Form builder using Twitter Bootstrap 3+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionpack5>=5.0:www/rubygem-actionpack5 \
		rubygem-activemodel5>=5.0:databases/rubygem-activemodel5

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
