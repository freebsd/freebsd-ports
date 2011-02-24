# New ports collection makefile for:	redis
# Date created:	   03 Jul 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	redis
DISTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A persistent key-value database with built-in net interface

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

CFLAGS+=	-I${LOCALBASE}/include

CONFLICTS?=	redis-2.2.*

USE_GMAKE=	yes
USE_RC_SUBR=	redis.sh
NO_LATEST_LINK=	yes
BIN_FILES=	redis-benchmark redis-check-aof redis-check-dump \
		redis-cli redis-server

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

PATTERN=	'16d;119d;15s|$$$$(ARCH) ||'
.if !defined(WITH_DEBUG)
PATTERN:=	${PATTERN:S/'$/;5s|^|\#|'/}
.endif

post-patch:
	${REINPLACE_CMD} ${PATTERN} ${WRKSRC}/Makefile

post-build:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/redis.conf > ${WRKDIR}/redis.conf

do-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKSRC}/!} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/redis.conf ${PREFIX}/etc/redis.conf.sample
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
