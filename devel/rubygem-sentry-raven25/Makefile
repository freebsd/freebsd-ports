# $FreeBSD$

PORTNAME=	sentry-raven
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	25

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday0>=0.7.6:www/rubygem-faraday0

PORTSCOUT=	limit:^2\.5
CONFLICTS_INSTALL=	rubygem-sentry-raven

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/raven

.include <bsd.port.mk>
