# Created by: gahr
# $FreeBSD$

PORTNAME=	cdash
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cdash.org/download/
DISTNAME=	CDash-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A web-based software testing server

LICENSE=	BSD

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=MYSQL

USE_ZIP=	yes
USES=		cmake:outsource
CMAKE_ARGS+=	-DCDASH_DB_NAME:STRING=cdash \
   		-DCDASH_DB_LOGIN:STRING=cdash \
   		-DCDASH_DB_TYPE:STRING=${DB_TYPE}
USE_PHP=	curl gd xsl

WRKSRC=		${WRKDIR}/${DISTNAME:S/./-/g}
SUB_FILES=	pkg-message
SUB_LIST+=	DB_TYPE=${DB_TYPE}

NO_STAGE=	yes
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
	${MKDIR} ${PREFIX}/www/CDash
	${RM} -f ${WRKSRC}/CMakeLists.txt.orig
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${PREFIX}/www/CDash
	${CHOWN} www ${PREFIX}/www/CDash/backup ${PREFIX}/www/CDash/rss

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
