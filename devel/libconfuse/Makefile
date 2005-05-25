# New ports collection makefile for:	libconfuse
# Date created:				18 September 2004
# Whom:					Juraj Lutter <otis@sk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libconfuse
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		ftp://ftp.wilbury.sk/pub/FreeBSD/local/distfiles/
MASTER_SITE_SUBDIR=	confuse
DISTNAME=	confuse-${PORTVERSION}

MAINTAINER=	otis@freebsd.sk
COMMENT=	Configuration file parsing library

.if defined(WITH_CHECK)
LIB_DEPENDS+=	${LOCALBASE}/lib/libcheck.a:${PORTSDIR}/devel/libcheck
.endif

USE_ICONV=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--disable-nls
CFLAGS+=	-I${WRKSRC}/src
.if defined(WITH_CHECK)
CONFIGURE_ARGS+=	--with-check=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
.endif

.include <bsd.port.mk>
