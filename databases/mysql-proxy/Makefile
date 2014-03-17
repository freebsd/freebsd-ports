# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mysql-proxy
PORTVERSION=	0.8.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQL-Proxy

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Monitor, analyze, or transform the communication of MySQL

LICENSE=	GPLv2

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent \
		libglib-2.0.so:${PORTSDIR}/devel/glib20

CONFIGURE_ARGS+=	--with-lua=lua-5.1 --with-mysql=${LOCALBASE}/bin/mysql_config --docdir=${DATADIR} --enable-self-contained
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LUA_PREFIX}/share/doc/${LUA_SUBDIR}/etc"
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
GNU_CONFIGURE=	yes
USES=		pkgconfig iconv
USE_LDCONFIG=	yes
USE_LUA=	5.1+
USE_MYSQL=	yes
USE_RC_SUBR=	mysql-proxy

.include <bsd.port.mk>
