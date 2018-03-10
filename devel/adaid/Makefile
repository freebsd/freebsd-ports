# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AdaID
PORTVERSION=	0.0.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Ada library for generating UUIDs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gprbuild:devel/gprbuild
TEST_DEPENDS=	${LOCALBASE}/lib/gnat/aunit.gpr:devel/aunit

USES=		ada:run
USE_GITHUB=	yes
GH_ACCOUNT=	anthony-arnold

LIB_VERSION=	1.0.2	# get from ${WRKSRC}/Makefile

post-patch:
	${SED} -e 's|"src"|"src", "include"|; s|%VERSION%|${LIB_VERSION}|' \
		${WRKSRC}/adaid.gpr.in > ${WRKSRC}/adaid.gpr
	${REINPLACE_CMD} -e 's|adaid_debug|adaid|' ${WRKSRC}/test.gpr

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BUILD_ARGS} \
		gprbuild -p -P adaid)

do-test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TEST_ARGS} \
		gprbuild -p -P test)
	${TEST_WRKSRC}/bin/test

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/adaid \
		${STAGEDIR}${PREFIX}/lib/adaid \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib/adaid
	${INSTALL_DATA} ${WRKSRC}/ali/*.ali* ${STAGEDIR}${PREFIX}/lib/adaid
	${INSTALL_DATA} ${WRKSRC}/src/*.adb ${WRKSRC}/include/*.ads \
		${STAGEDIR}${PREFIX}/include/adaid
	${INSTALL_DATA} ${FILESDIR}/adaid.gpr ${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
