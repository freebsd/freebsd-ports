# New ports collection makefile for:	ripperx
# Date created:		2006-12-26
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	ripperx
PORTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ripperX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK program to rip CD audio tracks and encode them

LIB_DEPENDS=	id3:${PORTSDIR}/audio/id3lib
RUN_DEPENDS=	cdparanoia:${PORTSDIR}/audio/cdparanoia

GNU_CONFIGURE=	yes
CFLAGS+=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack
MAN1=		ripperX.1

.include <bsd.port.mk>
