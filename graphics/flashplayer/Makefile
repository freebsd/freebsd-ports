# New ports collection makefile for:	flashplayer
# Date created:		2 October 1999
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flashplayer
PORTVERSION=	0.4.12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	GPL standalone Flash (TM) player

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash

WRKSRC=		${WRKDIR}/${DISTNAME}/player
USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/swfplayer

.include <bsd.port.mk>
