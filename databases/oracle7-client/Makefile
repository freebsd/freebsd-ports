# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	oracle7-client
PORTVERSION=	0.02
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.atnet.ru/pub/OS/FreeBSD/oracle/ \
		ftp://www.kuzbass.ru/pub/freebsd/oracle/
DISTNAME=	oracle7.client.OCI

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oracle 7 client

DEPRECATED=	Oracle 7 EOL by 13 years
EXPIRATION_DATE=	2017-03-07

ONLY_FOR_ARCHS=	i386
ORACLE_PREFIX=	oracle7
DIST_SUBDIR=	${ORACLE_PREFIX}
WRKSRC=		${WRKDIR}/${ORACLE_PREFIX}
ORACLE_HOME=	${PREFIX}/${ORACLE_PREFIX}
PLIST_SUB=	ORACLE_PREFIX="${ORACLE_PREFIX}"

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${ORACLE_HOME}
	${CP} -pRP ${WRKSRC}/network ${WRKSRC}/ocommon ${WRKSRC}/rdbms \
		${STAGEDIR}${ORACLE_HOME}
	${LN} -sf rdbms/lib ${STAGEDIR}${ORACLE_HOME}/lib
	@${ECHO_CMD} "-lwrap" >> ${STAGEDIR}${ORACLE_HOME}/lib/sysliblist

.include <bsd.port.mk>
