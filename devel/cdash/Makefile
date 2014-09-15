# Created by: gahr
# $FreeBSD$

PORTNAME=	cdash
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cdash.org/download/
DISTNAME=	CDash-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Web-based software testing server

LICENSE=	BSD3CLAUSE

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=MYSQL

USES=		cmake:outsource zip
CMAKE_ARGS+=	-DCDASH_DB_NAME:STRING=cdash \
   		-DCDASH_DB_LOGIN:STRING=cdash \
   		-DCDASH_DB_TYPE:STRING=${DB_TYPE}
USE_PHP=	curl gd xsl

WRKSRC=		${WRKDIR}/${DISTNAME:S/./-/g}
PLIST_SUB=	WWWOWN="${WWWOWN}"
SUB_FILES=	pkg-message
SUB_LIST+=	DB_TYPE=${DB_TYPE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_PHP+=	mysql
DB_TYPE=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
USE_PHP+=	pgsql
DB_TYPE=	pgsql
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/CDash
	${RM} -f ${WRKSRC}/CMakeLists.txt.orig
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/www/CDash

.include <bsd.port.mk>
