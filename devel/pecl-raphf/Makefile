# Created by: vanilla@
# $FreeBSD$

PORTNAME=	raphf
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Resource and persistent handles factory

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^1.*

USES=		gmake tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
