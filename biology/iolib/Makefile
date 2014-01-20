# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	io_lib
PORTVERSION=	1.13.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	staden/${PORTNAME}/${PORTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		gmake
USE_AUTOTOOLS=	libtool:env
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
