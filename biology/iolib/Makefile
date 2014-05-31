# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	io_lib
PORTVERSION=	1.13.7
CATEGORIES=	biology
MASTER_SITES=	SF/staden/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
