# New ports collection makefile for:	redis
# Date created:	   03 Jul 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	redis
PORTVERSION=	0.900
DISTVERSIONSUFFIX=	_2
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A persistent key-value database with built-in net interface

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include

USE_RC_SUBR=	redis.sh
BIN_FILES=	redis-server redis-benchmark redis-cli

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

REDIS_USER?=	redis
REDIS_UID?=	535
REDIS_GROUP?=	redis
REDIS_GID?=	535

REDIS_DBDIR?=	/var/db/redis
REDIS_RUNDIR?=	/var/run/redis
REDIS_LOGDIR?=	/var/log/redis

SUB_FILES=	pkg-message pkg-install
SUB_LIST+=	PORTNAME="${PORTNAME}" \
	REDIS_USER="${REDIS_USER}" \
	REDIS_UID="${REDIS_UID}" \
	REDIS_GROUP="${REDIS_GROUP}" \
	REDIS_GID="${REDIS_GID}" \
	REDIS_LOGDIR="${REDIS_LOGDIR}" \
	REDIS_DBDIR="${REDIS_DBDIR}" \
	REDIS_RUNDIR="${REDIS_RUNDIR}"

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/redis.conf > ${WRKDIR}/redis.conf

do-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/!} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/redis.conf ${PREFIX}/etc/redis.conf.sample
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
