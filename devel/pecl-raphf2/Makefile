PORTNAME=	raphf
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Resource and persistent handles factory
WWW=		https://pecl.php.net/package/raphf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	pecl infrastructure is being deprecated and no consumers for this port
EXPIRAION_DATE= 2026-09-30

USES=		gmake php:pecl
IGNORE_WITH_PHP=	86

PORTSCOUT=	limit:^2.*

CONFLICTS=	pecl-raphf-1*

.include <bsd.port.mk>
