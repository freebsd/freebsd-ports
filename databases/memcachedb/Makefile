# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcachedb
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	k@stereochro.me
COMMENT=	Distributed storage system designed for persistence

DEPRECATED=	Depends on deprecated Berkeley DB version, needs porting to DB_SITE
EXPIRATION_DATE=2014-11-30

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

CFLAGS+=	-I"${BDB_INCLUDE_DIR}"
CONFIGURE_ARGS=	--enable-threads --with-bdb="${LOCALBASE}" \
		--with-libevent="${LOCALBASE}"
GNU_CONFIGURE=	yes
LDFLAGS+=	-l"${BDB_LIB_NAME}" -L"${LOCALBASE}/lib"
USE_BDB=	48
USE_RC_SUBR=	${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}/var/db/memcachedb

.include <bsd.port.mk>
