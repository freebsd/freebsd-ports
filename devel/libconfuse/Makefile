# New ports collection makefile for:	libconfuse
# Date created:				18 September 2004
# Whom:					Juraj Lutter <otis@sk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libconfuse
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	http://bzero.se/confuse/
MASTER_SITE_SUBDIR=	confuse
DISTNAME=	confuse-${PORTVERSION}

MAINTAINER=	otis@freebsd.sk
COMMENT=	Configuration file parsing library

.if defined(WITH_CHECK)
LIB_DEPENDS+=	${LOCALBASE}/lib/libcheck.a:${PORTSDIR}/devel/libcheck
.endif

USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig
CONFIGURE_ARGS+=	--disable-nls
CFLAGS+=	-I${WRKSRC}/src
.if defined(WITH_CHECK)
CONFIGURE_ARGS+=	--with-check=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
.endif

.include <bsd.port.mk>
