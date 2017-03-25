# $FreeBSD$

PORTNAME=	google-api-client
PORTVERSION=	0.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client for accessing Google APIs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.3:www/rubygem-addressable \
		rubygem-googleauth>=0.5:security/rubygem-googleauth \
		rubygem-httpclient>=2.7:www/rubygem-httpclient \
		rubygem-hurley>=0.1:www/rubygem-hurley \
		rubygem-memoist>=0.11:devel/rubygem-memoist \
		rubygem-mime-types>=1.6:misc/rubygem-mime-types \
		rubygem-representable>=3.0:textproc/rubygem-representable \
		rubygem-retriable>=2.0:devel/rubygem-retriable

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
