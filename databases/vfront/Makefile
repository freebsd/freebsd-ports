# $FreeBSD$

PORTNAME=	vfront
DISTVERSION=	0.96c
CATEGORIES=	databases www
MASTER_SITES=	SF/vfront/vfront/vfront-${DISTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Simple frontend for database data entry

LICENSE=	GPLv2

NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

USE_PHP=	yes

OPTIONS_MULTI=	database
OPTIONS_MULTI_database=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL PGSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysqli
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
USE_PGSQL=	yes
.endif

post-patch:
	${REINPLACE_CMD} -i '' -e \
		's/\(AUTHORIZATION \\*"\)postgres\(\\*"\)/\1pgsql\2/' \
	    ${WRKSRC}/_install/vfront.postgres.sql \
	    ${WRKSRC}/_install/vfront.postgres.sql.php

pre-install:
	(cd ${WRKSRC} && \
	    ${FIND} * -type f | ${SED} 's,^,%%WWWDIR%%/,' > ${PLIST} && \
	    ${FIND} * -type d | ${SORT} -r | \
			${SED} 's,^,@dirrmtry %%WWWDIR%%/,' >> ${PLIST})
	@${ECHO_CMD} '@dirrmtry %%WWWDIR%%' >> ${PLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN} %D/%%WWWDIR%%' >> ${PLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 700 %D/%%WWWDIR%%/conf' >> ${PLIST}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
