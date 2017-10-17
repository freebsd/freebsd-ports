# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	argp-standalone
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~nisse/misc/ \
		LOCAL/sem

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone version of arguments parsing functions from GLIBC

LICENSE=	LGPL20+ PD
LICENSE_COMB=	multi

USES=		autoreconf libtool
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/libargp.a \
		lib/libargp.so lib/libargp.so.0 lib/libargp.so.0.0.0 \
		include/argp.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/argp.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
