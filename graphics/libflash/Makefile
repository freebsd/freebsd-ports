# New ports collection makefile for:	FlashLib
# Date created:		10 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libflash
PORTVERSION=	0.4.13
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/gplflash/gplflash/${PORTVERSION}
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	GPL Flash (TM) Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		jpeg.10:${PORTSDIR}/graphics/jpeg

USE_XORG=	x11 xext xkbfile xt
WRKSRC=		${WRKDIR}/${DISTNAME}/lib
USE_AUTOTOOLS=	libtool:22
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_BZIP2=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/swf.h

.include <bsd.port.mk>
