# Created by: Kiyoshi Matsui <kmatsui@t3.rim.or.jp>
# $FreeBSD$

PORTNAME=	mcpp
PORTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V.${PORTVERSION}

MAINTAINER=	kmatsui@t3.rim.or.jp
COMMENT=	Alternative C/C++ preprocessor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mcpplib

PLIST_FILES=	bin/mcpp    \
		lib/libmcpp.so	\
		lib/libmcpp.so.3	\
		lib/libmcpp.a	\
		lib/libmcpp.la	\
		include/mcpp_lib.h \
		include/mcpp_out.h \
		man/man1/mcpp.1.gz \
		share/doc/mcpp/LICENSE  \
		share/doc/mcpp/NEWS     \
		share/doc/mcpp/README   \
		share/doc/mcpp/mcpp-manual.html  \
		share/doc/mcpp/mcpp-manual-jp.html
PLIST_DIRS=	share/doc/mcpp

.include <bsd.port.mk>
