# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libeio
PORTVERSION=	4.18.0
CATEGORIES=	devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Full-featured asynchronous I/O library for C

USE_GITHUB=	yes
GH_ACCOUNT=	scunningham
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	e1a62ab
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

PLIST_FILES=	include/eio.h lib/libeio.a lib/libeio.la \
		lib/libeio.so lib/libeio.so.1

NO_STAGE=	yes
.include <bsd.port.mk>
