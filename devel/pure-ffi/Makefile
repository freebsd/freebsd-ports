# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-ffi
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to libffi

LIB_DEPENDS+=	ffi:${PORTSDIR}/devel/libffi

USE_PURE=	yes

PLIST_FILES=	lib/pure/ffi.pure \
		lib/pure/ffi.so

.include "${.CURDIR}/../../lang/pure/bsd.pure.mk"
.include <bsd.port.mk>
