# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	libcddb
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library to access data on a CDDB server

GNU_CONFIGURE=	yes
USES=		iconv libtool pathfix tar:bzip2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-cdio
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
