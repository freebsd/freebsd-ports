PORTNAME=	vfront
DISTVERSION=	0.96c
PORTREVISION=	2
CATEGORIES=	databases www
MASTER_SITES=	SF/vfront/vfront/vfront-${DISTVERSION}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Simple frontend for database data entry
WWW=		http://www.vfront.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license

USES=		cpe php

NO_ARCH=	yes
NO_BUILD=	yes

PLIST=		${WRKDIR}/pkg-plist

OPTIONS_DEFAULT=	MYSQL PGSQL
OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=	MYSQL PGSQL

MYSQL_USES=	mysql
MYSQL_USE=	PHP=mysqli
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
	@${ECHO_CMD} '@postexec ${CHOWN} -R ${WWWOWN} %D/%%WWWDIR%%' >> ${PLIST}
	@${ECHO_CMD} '@postexec ${CHMOD} 700 %D/%%WWWDIR%%/conf' >> ${PLIST}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
