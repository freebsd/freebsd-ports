# Ports collection Makefile for:	vfront
# Date created:	 			11th April 2012
# Whom:					crees
#
# $FreeBSD$
#

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

OPTIONS+=	MYSQL "Use MySQL databases"		off
OPTIONS+=	PGSQL "Use PostgreSQL databases"	off

.include <bsd.port.options.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	mysqli
USE_MYSQL=	yes
.endif

.if defined(WITH_PGSQL)
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

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})
	${CHOWN} -R ${WWWOWN} ${WWWDIR}
	${CHMOD} 700 ${WWWDIR}/conf

.include <bsd.port.mk>
