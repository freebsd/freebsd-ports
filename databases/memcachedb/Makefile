# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcachedb
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	k@stereochro.me
COMMENT=	Distributed storage system designed for persistence

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

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
