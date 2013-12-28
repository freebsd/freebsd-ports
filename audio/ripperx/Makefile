# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	ripperx
PORTVERSION=	2.7.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ripperX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK program to rip CD audio tracks and encode them

LIB_DEPENDS=	libid3.so:${PORTSDIR}/audio/id3lib
RUN_DEPENDS=	cdparanoia:${PORTSDIR}/audio/cdparanoia

GNU_CONFIGURE=	yes
CFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20

.include <bsd.port.mk>
