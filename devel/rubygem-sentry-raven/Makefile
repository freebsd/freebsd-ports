PORTNAME=	sentry-raven
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday1>=1.0:www/rubygem-faraday1

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/raven

.include <bsd.port.mk>
