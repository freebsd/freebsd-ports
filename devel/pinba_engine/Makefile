# Created by: raven428 <raven428@gmail.com>
# $FreeBSD$

PORTNAME=	pinba_engine
PORTVERSION=	2011.08.18
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tony2001/pinba_engine/tarball/${GITVERSION}/
DISTNAME=	tony2001-pinba_engine-${GITVERSION}

MAINTAINER=	raven428@gmail.com
COMMENT=	Mysql-engine part of statistics server for PHP

BUILD_DEPENDS=	${LOCALBASE}/include/google/protobuf/descriptor.h:${PORTSDIR}/devel/protobuf \
 		${LOCALBASE}/include/event.h:${PORTSDIR}/devel/libevent2 \
		${LOCALBASE}/include/Judy.h:${PORTSDIR}/devel/judy \
		${LOCALBASE}/lib/mysql/plugin:${PORTSDIR}/${_MYSQL_SERVER} \
 		${NONEXISTENT}:${PORTSDIR}/${_MYSQL_SERVER}:configure \
		bison:${PORTSDIR}/devel/bison \
		cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

GITVERSION=	3a0cb51

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	50

MYSQL_WRKSRC=	$$(cd ${PORTSDIR}/${_MYSQL_SERVER} && ${MAKE} -V WRKSRC)

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
USE_LDCONFIG=	${PREFIX}/lib/mysql/plugin

AUTOMAKE_ARGS=	--add-missing --copy --force-missing
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
