# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libeio
PORTVERSION=	4.18.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Full-featured asynchronous I/O library for C

USE_GITHUB=	yes
GH_ACCOUNT=	scunningham
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	e1a62ab
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

PLIST_FILES=	include/eio.h lib/libeio.a lib/libeio.so \
		lib/libeio.so.1 lib/libeio.so.1.0.0

.include <bsd.port.mk>
