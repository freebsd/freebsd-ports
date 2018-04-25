# $FreeBSD$

PORTNAME=	clixon
DISTVERSION=	3.6.0.b.20180424
CATEGORIES=	devel

MAINTAINER=	dcornejo@netgate.com
COMMENT=	CLIgen is a Command-Line Interface generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcligen.so:devel/cligen \
		libfcgi.so:www/fcgi

USES=		gmake

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	clicon
GH_TAGNAME=	d57a6cf53cdda4a3e5da122eb34de5ce069676f0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cligen=${LOCALBASE} --sysconfdir=${ETCDIR}

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
