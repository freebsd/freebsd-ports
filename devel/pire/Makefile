# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pire
PORTVERSION=	0.0.6
DISTVERSIONPREFIX=	release-
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Perl Incompatible Regular Expressions library

LICENSE=	LGPL3+ MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	yandex

USES=		autoreconf bison compiler:c++11-lib libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
TEST_TARGET=	check

.include <bsd.port.mk>
