# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pire
PORTVERSION=	0.0.5
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Perl Incompatible Regular Expressions library

USE_GITHUB=	yes
GH_ACCOUNT=	dprokoptsev
GH_TAGNAME=	release-${PORTVERSION}
GH_COMMIT=	012bedf

LICENSE=	LGPL3

USE_AUTOTOOLS=	autoconf automake libtool libtoolize
GNU_CONFIGURE=	yes
USES=		gmake bison
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	not yet ported to big-endian platforms

OPTIONS_DEFINE=	UNITTEST
UNITTEST_DESC=	Compile with unittest support

.include <bsd.port.options.mk>

run-autotools:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -fi

.if ${PORT_OPTIONS:MUNITTEST} || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	cppunit-config:${PORTSDIR}/devel/cppunit
CONFIGURE_ARGS=	--with-cppunit-prefix=${LOCALBASE}

regression-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check || \
		(${CAT} ${WRKSRC}/tests/test-suite.log; false)
.endif

.include <bsd.port.mk>
