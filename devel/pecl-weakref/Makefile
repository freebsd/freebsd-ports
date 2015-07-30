# Created by: Daniel O'Connor <darius@dons.net.au.
# $FreeBSD$

PORTNAME=	weakref
PORTVERSION=	0.2.6
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL
DISTNAME=	Weakref-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weakref class

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz
USE_PHP=	pcre
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

.include <bsd.port.mk>
