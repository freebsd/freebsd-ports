# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	memcacheq
PORTVERSION=	0.2.0
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	GENTOO

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Simple queue service over Memcache

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USE_CSTD=	gnu89
CFLAGS+=	-I"${BDB_INCLUDE_DIR}"
LDFLAGS+=	-l"${BDB_LIB_NAME}" -L"${LOCALBASE}/lib"

USES=		bdb:5
USE_RC_SUBR=	memcacheq
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} --with-bdb=${LOCALBASE} --enable-threads

PORTDOCS=	README

MCQDIR?=	/var/db/memcacheq
PLIST_SUB=	MCQDIR=${MCQDIR}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${MCQDIR}

.include <bsd.port.mk>
