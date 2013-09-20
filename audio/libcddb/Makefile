# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	libcddb
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library to access data on a CDDB server

USE_BZIP2=	yes
NO_STAGE=	yes
GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig iconv
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-cdio
CPPFLAGS+=	-DICONV_CONST="const" -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
