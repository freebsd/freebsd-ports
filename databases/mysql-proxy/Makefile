# New ports collection makefile for:	mysql-proxy
# Date created:		2007-06-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-proxy
PORTVERSION=	0.5.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	MySQL-Proxy

MAINTAINER=	gslin@gslin.org
COMMENT=	Monitor, analyze or transform the communication of MySQL

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent \
		glib:${PORTSDIR}/devel/glib20

CONFIGURE_ARGS+=	--with-lua --with-mysql
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		PKG_CONFIG_PATH="${LUA_PREFIX}/share/doc/${LUA_SUBDIR}/etc"
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_ICONV=	yes
USE_LUA=	5.1+
USE_MYSQL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}r8

PLIST_FILES=	sbin/mysql-proxy

.include <bsd.port.mk>
