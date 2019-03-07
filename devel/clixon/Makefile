# $FreeBSD$

PORTNAME=	clixon
PORTVERSION=	3.9.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	dcornejo@netgate.com
COMMENT=	CLIgen is a Command-Line Interface generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcligen.so:devel/cligen \
		libfcgi.so:www/fcgi
BUILD_DEPENDS=	cligen>=3.9.0:devel/cligen

USES=		autoreconf bison gmake

USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	clicon
MAKE_ARGS=	wwwdir=${PREFIX}/sbin wwwuser=${WWWOWN}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cligen=${LOCALBASE} --sysconfdir=${ETCDIR}

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
