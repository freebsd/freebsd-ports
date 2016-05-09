# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adabase
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Thick database bindings for Ada

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada
USE_GITHUB=	yes
GH_ACCOUNT=	jrmarino
GH_PROJECT=	AdaBase

MAKE_ENV+=	OS_VERSION=unix

post-extract:
	${RM} ${WRKSRC}/src/drivers/adabase-driver-base-firebird.ad?

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		gprbuild -p -P adabase ${BUILD_ARGS})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/adabase \
		${STAGEDIR}${PREFIX}/lib/adabase \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib/adabase
	${INSTALL_DATA} ${WRKSRC}/src/*/*.ad[bs] ${WRKSRC}/src/adabase.ads \
		${STAGEDIR}${PREFIX}/include/adabase
	${INSTALL_DATA} ${FILESDIR}/adabase.gpr ${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
