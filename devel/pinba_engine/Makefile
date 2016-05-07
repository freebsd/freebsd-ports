# Created by: raven428 <raven428@gmail.com>
# $FreeBSD$

PORTNAME=	pinba_engine
PORTVERSION=	2011.08.18
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	raven428@gmail.com
COMMENT=	Mysql-engine part of statistics server for PHP

BUILD_DEPENDS=	${LOCALBASE}/include/google/protobuf/descriptor.h:devel/protobuf \
		${LOCALBASE}/include/event.h:devel/libevent2 \
		${LOCALBASE}/include/Judy.h:devel/judy \
		${LOCALBASE}/lib/mysql/plugin:${_MYSQL_SERVER} \
		${NONEXISTENT}:${_MYSQL_SERVER}:configure \
		bison:devel/bison \
		cmake:devel/cmake
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USE_GITHUB=	yes
GH_ACCOUNT=	tony2001
GH_TAGNAME=	3a0cb51

USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	50

MYSQL_WRKSRC=	$$(cd ${PORTSDIR}/${_MYSQL_SERVER} && ${MAKE} -V WRKSRC)

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gmake libtool
USE_LDCONFIG=	${PREFIX}/lib/mysql/plugin

CONFIGURE_ARGS=	--disable-static \
		--with-mysql=${MYSQL_WRKSRC} \
		--libdir=${PREFIX}/lib/mysql/plugin
CFLAGS+=	-I${LOCALBASE}/include/mysql

SUB_FILES=	pkg-message
PORTDOCS=	NEWS TODO README

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL} ${WRKSRC}/default_tables.sql ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
