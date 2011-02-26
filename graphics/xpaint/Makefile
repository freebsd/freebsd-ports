# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.9.8.2
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A simple paint program

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XORG=	xft xmu xpm

MAN1=		xpaint.1

post-extract:
	@${MKDIR} ${WRKSRC}/X11
	@${LN} -sf ../xaw3dxft ${WRKSRC}/X11/Xaw3d

post-patch:
	@${REINPLACE_CMD} -e \
		's|@PREFIX@|${PREFIX}|g ; \
		 s|@XPMDIR@|${LOCALBASE}|g ; \
		 s|@LOCALBASE@|${LOCALBASE}|g' ${WRKSRC}/Local.config

pre-configure:
	@cd ${WRKSRC} && ${SH} ./configure xaw3dxft.a

.include <bsd.port.mk>
