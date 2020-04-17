# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcircllhist
PORTVERSION=	g20200417
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Circonus log-linear histogram C implementation

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	circonus-labs
GH_TAGNAME=	b7c6248

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/circllhist_print \
		include/circllhist.h lib/libcircllhist.a \
		lib/libcircllhist.so lib/libcircllhist.so.0.0.1 \
		share/lua/5.1/ffi_libcircllhist.lua

.include <bsd.port.mk>
