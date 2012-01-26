# New ports collection makefile for:	pure-ffi
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

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

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
