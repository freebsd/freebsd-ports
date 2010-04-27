# New ports collection makefile for:	mysql-proxy
# Date created:		2007-06-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-proxy
PORTVERSION=	0.8.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQL-Proxy

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Monitor, analyze or transform the communication of MySQL

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent \
		glib:${PORTSDIR}/devel/glib20

CONFIGURE_ARGS+=	--with-lua=lua-5.1 --with-mysql --docdir=${DATADIR} --enable-self-contained
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		PKG_CONFIG_PATH="${LUA_PREFIX}/share/doc/${LUA_SUBDIR}/etc"
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LUA=	5.1+
USE_MYSQL=	yes
USE_RC_SUBR=	mysql-proxy.sh
IGNORE_WITH_MYSQL=	323 40

.include <bsd.port.mk>
