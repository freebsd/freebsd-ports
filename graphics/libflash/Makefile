# New ports collection makefile for:	FlashLib
# Date created:		10 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libflash
PORTVERSION=	0.4.13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	GPL Flash (TM) Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${DISTNAME}/lib
USE_LIBTOOL_VER=	15
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_BZIP2=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/swf.h

.include <bsd.port.mk>
