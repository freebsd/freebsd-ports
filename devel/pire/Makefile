# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pire
PORTVERSION=	0.0.5
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Perl Incompatible Regular Expressions library

USE_GITHUB=	yes
GH_ACCOUNT=	dprokoptsev

LICENSE=	LGPL3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf bison gmake libtool
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	not yet ported to big-endian platforms

OPTIONS_DEFINE=	UNITTEST
UNITTEST_DESC=	Compile with unittest support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNITTEST} || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	cppunit-config:${PORTSDIR}/devel/cppunit
CONFIGURE_ARGS+=--with-cppunit-prefix=${LOCALBASE}

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check || \
		(${CAT} ${WRKSRC}/tests/test-suite.log; false)
.endif

.include <bsd.port.mk>
