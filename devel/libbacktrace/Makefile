PORTNAME=	libbacktrace
DISTVERSION=	1.0-20221130 # from README: This is version 1.0. It is likely that this will always be version 1.0.
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library that produces symbolic backtraces in C/C++ programs
WWW=		https://github.com/ianlancetaylor/libbacktrace

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ianlancetaylor
GH_TAGNAME=	14818b7

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/backtrace-supported.h \
		include/backtrace.h \
		lib/libbacktrace.a \
		lib/libbacktrace.so \
		lib/libbacktrace.so.0 \
		lib/libbacktrace.so.0.0.0

.include <bsd.port.mk>
