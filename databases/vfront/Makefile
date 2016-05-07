# $FreeBSD$

PORTNAME=	vfront
DISTVERSION=	0.96c
CATEGORIES=	databases www
MASTER_SITES=	SF/vfront/vfront/vfront-${DISTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Simple frontend for database data entry

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license

BROKEN_powerpc64=	Does not build

NO_BUILD=	yes
NO_ARCH=	yes
PLIST=		${WRKDIR}/pkg-plist

USE_PHP=	yes

OPTIONS_MULTI=	database
OPTIONS_MULTI_database=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL PGSQL

MYSQL_USE=	MYSQL=yes PHP=mysqli
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pgsql

post-patch:
	${REINPLACE_CMD} -i '' -e \
		's/\(AUTHORIZATION \\*"\)postgres\(\\*"\)/\1pgsql\2/' \
	    ${WRKSRC}/_install/vfront.postgres.sql \
	    ${WRKSRC}/_install/vfront.postgres.sql.php

pre-install:
	(cd ${WRKSRC} && \
	    ${FIND} * -type f | ${SED} 's,^,%%WWWDIR%%/,' > ${PLIST} && \
	    ${FIND} * -type d -empty | ${SORT} -r | \
			${SED} 's,^,@dir %%WWWDIR%%/,' >> ${PLIST})
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN} %D/%%WWWDIR%%' >> ${PLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 700 %D/%%WWWDIR%%/conf' >> ${PLIST}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
