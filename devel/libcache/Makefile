# New ports collection makefile for:	libcache
# Date created:		04 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libcache
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.afro-productions.com/

MAINTAINER=	ports@FreeBSD.org

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared
WRKSRC=		${WRKDIR}/libcache
VERSION=	0
PLIST_SUB+=	VERSION="${VERSION}"
MAKE_ENV+=	PCFLAGS="${CFLAGS}"

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libcache.so ${PREFIX}/lib/libcache.so.${VERSION}
	@${LN} -sf ${PREFIX}/lib/libcache.so.${VERSION} ${PREFIX}/lib/libcache.so

.include <bsd.port.mk>
