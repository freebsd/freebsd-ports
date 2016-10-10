# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libuutil
PORTVERSION=	1.0.3
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Illumos userland utilities library

LICENSE=	CDDL

GH_ACCOUNT=	jrmarino
USE_GITHUB=	yes

USES=		uidfix
MAKE_ARGS=	LIBDIR=${PREFIX}/lib
USE_LDCONFIG=	yes

PLIST_FILES=	include/libuutil.h \
		lib/libuutil.a \
		lib/libuutil.so \
		lib/libuutil.so.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/libuutil.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
