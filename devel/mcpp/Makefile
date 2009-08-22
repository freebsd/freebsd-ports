# New ports collection makefile for:   mcpp
# Date created:		06 April 2007
# Whom:			Kiyoshi Matsui <kmatsui@t3.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mcpp
PORTVERSION=	2.7.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/V.${PORTVERSION}

MAINTAINER=	kmatsui@t3.rim.or.jp
COMMENT=	Alternative C/C++ preprocessor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mcpplib
MAN1=		mcpp.1

PLIST_FILES=	bin/mcpp    \
		lib/libmcpp.so	\
		lib/libmcpp.so.3	\
		lib/libmcpp.a	\
		lib/libmcpp.la	\
		include/mcpp_lib.h \
		include/mcpp_out.h \
		share/doc/mcpp/LICENSE  \
		share/doc/mcpp/NEWS     \
		share/doc/mcpp/README   \
		share/doc/mcpp/mcpp-manual.html  \
		share/doc/mcpp/mcpp-manual-jp.html
PLIST_DIRS=	share/doc/mcpp

.include <bsd.port.mk>
