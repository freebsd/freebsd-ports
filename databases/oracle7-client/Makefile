# New ports collection makefile for:	oracle7-client
# Date created:		3 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	oracle7-client
PORTVERSION=	0.01
CATEGORIES=	databases
MASTER_SITES=	\
		ftp://ftp.atnet.ru/pub/OS/FreeBSD/oracle/ \
		ftp://ftp.lipetsk.ru/pub/unix/Oracle/FreeBSD/ \
		ftp://ftp.redcom.ru/pub/Oracle/freebsd-client7/
DISTNAME=	oracle7.client.OCI

MAINTAINER=	skv@FreeBSD.org

ORACLE_PREFIX=	oracle7
DIST_SUBDIR=	${ORACLE_PREFIX}
WRKSRC=		${WRKDIR}/${ORACLE_PREFIX}
ORACLE_HOME=	${PREFIX}/${ORACLE_PREFIX}
PLIST_SUB=	ORACLE_PREFIX="${ORACLE_PREFIX}"

NO_BUILD=	yes

pre-install:
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
		@${CP} -pRP ${WRKSRC}/network ${WRKSRC}/ocommon \
			${WRKSRC}/rdbms ${ORACLE_HOME}
		@${LN} -sf rdbms/lib ${ORACLE_HOME}/lib

post-install:
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
