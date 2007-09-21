# New ports collection makefile for:	mysql-proxy
# Date created:		2007-06-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-proxy
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQL-Proxy

MAINTAINER=	gslin@gslin.org
COMMENT=	Monitor, analyze or transform the communication of MySQL

LIB_DEPENDS=	event-1.3d:${PORTSDIR}/devel/libevent \
		glib:${PORTSDIR}/devel/glib20

CONFIGURE_ARGS+=	--datadir="${DATADIR}" --with-lua --with-mysql
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		PKG_CONFIG_PATH="${LUA_PREFIX}/share/doc/${LUA_SUBDIR}/etc"
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_ICONV=	yes
USE_LUA=	5.1+
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323 40 41

.include <bsd.port.mk>
