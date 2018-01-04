# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pire
PORTVERSION=	0.0.5
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Perl Incompatible Regular Expressions library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	dprokoptsev

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf bison libtool
USE_LDCONFIG=	yes
TEST_TARGET=	check

.include <bsd.port.mk>
