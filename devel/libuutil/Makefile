# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libuutil
PORTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Illumos userland utilities library

LICENSE=	CDDL

GH_ACCOUNT=	jrmarino
USE_GITHUB=	yes

BROKEN=		produces broken library (undefined reference to `avl_*')

USES=		uidfix
MAKE_ARGS=	LIBDIR=${PREFIX}/lib
USE_LDCONFIG=	yes

PLIST_FILES=	include/libuutil.h lib/libuutil.a lib/libuutil.so \
		lib/libuutil.so.1

post-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} libuutil.h \
		${STAGEDIR}${PREFIX}/include/)

.include <bsd.port.mk>
