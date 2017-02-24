# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	io_lib
PORTVERSION=	1.14.9
CATEGORIES=	biology

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	jkbonfield
GH_TAGNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
