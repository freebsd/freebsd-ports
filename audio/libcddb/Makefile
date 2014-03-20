# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	libcddb
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library to access data on a CDDB server

GNU_CONFIGURE=	yes
USES=		iconv libtool:oldver pathfix tar:bzip2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-cdio
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
