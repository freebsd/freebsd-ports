# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adabase
PORTVERSION=	2.0
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

OPTIONS_MULTI=		DBASE
OPTIONS_MULTI_DBASE=	MYSQL SQLITE
OPTIONS_DEFAULT=	MYSQL SQLITE
OPTIONS_SUB=		yes

SQLITE_MAKE_ENV=	SQLITE=yes
SQLITE_USES=		sqlite:3
SQLITE_VARS=		DRVSQLITE=yes
SQLITE_VARS_OFF=	DRVSQLITE=no

MYSQL_MAKE_ENV=		MYSQL=yes
MYSQL_USES=		mysql
MYSQL_VARS=		DRVMYSQL=yes
MYSQL_VARS_OFF=		DRVMYSQL=no

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
	${SED} -e "s|@PREFIX@|${PREFIX}|" \
	       -e "s|@MYSQL@|${DRVMYSQL}|" \
	       -e "s|@SQLITE@|${DRVSQLITE}|" ${WRKSRC}/adabase.gpr.in > \
		${STAGEDIR}${PREFIX}/lib/gnat/adabase.gpr

.include <bsd.port.mk>
