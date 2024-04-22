PORTNAME=	rationl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-139
DISTVERSIONSUFFIX=	-g9e32a19
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Expressive regular expression library written in C
WWW=		https://github.com/TheNaturLFoundation/rationL

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	criterion>0:devel/criterion

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	TheNaturLFoundation
GH_PROJECT=	rationL

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
