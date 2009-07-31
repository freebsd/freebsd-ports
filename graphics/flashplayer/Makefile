# New ports collection makefile for:	flashplayer
# Date created:		2 October 1999
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flashplayer
PORTVERSION=	0.4.13
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	GPL standalone Flash (TM) player

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash

WRKSRC=		${WRKDIR}/${DISTNAME}/player
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11 xaw xkbfile
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/swfplayer

.include <bsd.port.mk>
