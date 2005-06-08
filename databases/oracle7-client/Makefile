# New ports collection makefile for:	oracle7-client
# Date created:		3 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	oracle7-client
PORTVERSION=	0.02
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.atnet.ru/pub/OS/FreeBSD/oracle/ \
		ftp://www.kuzbass.ru/pub/freebsd/oracle/
DISTNAME=	oracle7.client.OCI

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Oracle 7 client

ONLY_FOR_ARCHS=	i386
ORACLE_PREFIX=	oracle7
DIST_SUBDIR=	${ORACLE_PREFIX}
WRKSRC=		${WRKDIR}/${ORACLE_PREFIX}
ORACLE_HOME=	${PREFIX}/${ORACLE_PREFIX}
PLIST_SUB=	ORACLE_PREFIX="${ORACLE_PREFIX}"

NO_BUILD=	yes

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${CP} -pRP ${WRKSRC}/network ${WRKSRC}/ocommon ${WRKSRC}/rdbms \
		${ORACLE_HOME}
	@${LN} -sf rdbms/lib ${ORACLE_HOME}/lib
	@${ECHO_CMD} "-lwrap" >> ${ORACLE_HOME}/lib/sysliblist

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
