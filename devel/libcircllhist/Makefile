# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcircllhist
PORTVERSION=	g20190612
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C implementation of Circonus log-linear histograms

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	circonus-labs
GH_TAGNAME=	5b43fe1

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/circllhist.h lib/libcircllhist.a \
		lib/libcircllhist.so lib/libcircllhist.so.0.0.1 \
		share/lua/5.1/ffi_libcircllhist.lua

post-patch:
	@${REINPLACE_CMD} -e 's,-O5 ,,' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
