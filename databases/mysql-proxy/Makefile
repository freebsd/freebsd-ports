# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mysql-proxy
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	MYSQL/MySQL-Proxy

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Monitor, analyze, or transform the communication of MySQL

LICENSE=	GPLv2

LIB_DEPENDS=	libevent.so:devel/libevent2 \
		libglib-2.0.so:devel/glib20

CONFIGURE_ARGS+=	--with-lua=lua-${LUA_VER} --with-mysql=${LOCALBASE}/bin/mysql_config --docdir=${DATADIR} --enable-self-contained
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LUA_PREFIX}/share/doc/${LUA_SUBDIR}/etc"
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
GNU_CONFIGURE=	yes
USES=		pkgconfig lua:51 iconv libtool
USE_LDCONFIG=	yes
USE_MYSQL=	yes
USE_RC_SUBR=	mysql-proxy

.include <bsd.port.mk>
