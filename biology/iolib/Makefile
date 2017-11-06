# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	io_lib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1-14-9
CATEGORIES=	biology

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

BROKEN_powerpc64=	fails to compile: bgzip.c: error: invalid operands to binary &

USE_GITHUB=	yes
GH_ACCOUNT=	jkbonfield

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
