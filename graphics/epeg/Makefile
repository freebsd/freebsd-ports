# Created by: vanilla
# $FreeBSD$

PORTNAME=	epeg
PORTVERSION=	0.9.1.042
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Immensely fast JPEG thumbnailing library

GNU_CONFIGURE=	yes
USES=		jpeg libtool pathfix tar:bzip2
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
