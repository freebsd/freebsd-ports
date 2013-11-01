# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tine20
PORTVERSION=	0.0.2012.10.04
DISTVERSIONSUFFIX=	2012.10.4
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.tine20.org/downloads/${DISTVERSIONSUFFIX}/
DISTNAME=	${PORTNAME}-allinone_${DISTVERSIONSUFFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Professional Open Source Groupware and CRM

LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes

FETCH_ARGS=	-Fpr

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	DISTNAME=${DISTNAME}

OPTIONS_DEFINE=	LDAP APC MEMCACHE
APC_DESC=	Enable pecl-APC support
MEMCACHE_DESC=	Enable pecl-memcache support

USE_MYSQL=	yes
USE_PHP=	ctype dom gd iconv json mcrypt mysql pdo_mysql simplexml spl xml zip
WANT_PHP_WEB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPC}
USE_PHP+=	apc
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
USE_PHP+=	memcache
.endif

.include <bsd.port.pre.mk>
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}/${PORTNAME}
	cd ${WRKDIR}/${PORTNAME} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
