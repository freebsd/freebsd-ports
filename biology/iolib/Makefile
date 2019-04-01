# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	io_lib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1-14-10
CATEGORIES=	biology

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	jkbonfield

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lpthread

.include <bsd.port.mk>
