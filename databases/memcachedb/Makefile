# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcachedb
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	meritus@innervision.pl
COMMENT=	Distributed storage system designed for persistent

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

CFLAGS=		-I"${BDB_INCLUDE_DIR}"
CONFIGURE_ARGS=	--enable-threads --with-bdb="${LOCALBASE}" \
		--with-libevent="${LOCALBASE}"
GNU_CONFIGURE=	yes
LDFLAGS+=	-l"${BDB_LIB_NAME}" -L"${LOCALBASE}/lib"
MCDBDIR?=	/var/db/memcachedb
USE_BDB=	47+
USE_RC_SUBR=	${PORTNAME}

NO_STAGE=	yes
post-install:
	${MKDIR} ${MCDBDIR} || ${TRUE}
	${CHOWN} nobody:nobody ${MCDBDIR}

.include <bsd.port.mk>
