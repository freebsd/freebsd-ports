# Created by: Kiyoshi Matsui <kmatsui@t3.rim.or.jp>
# $FreeBSD$

PORTNAME=	mcpp
PORTVERSION=	2.7.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V.${PORTVERSION}

MAINTAINER=	kmatsui@t3.rim.or.jp
COMMENT=	Alternative C/C++ preprocessor

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mcpplib

PLIST_FILES=	bin/mcpp    \
		lib/libmcpp.so	\
		lib/libmcpp.so.0	\
		lib/libmcpp.so.0.3.0	\
		lib/libmcpp.a	\
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
