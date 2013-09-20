# Created by: Martin Sugioarto <martin.sugioarto@udo.edu>
# $FreeBSD$

PORTNAME=	iiview
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	martin.sugioarto@udo.edu
COMMENT=	Thumb viewer application

BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png \
		${LOCALBASE}/lib/libtiff.a:${PORTSDIR}/graphics/tiff \
		${LOCALBASE}/lib/libjpeg.a:${PORTSDIR}/graphics/jpeg

USE_XORG=	xpm x11
PLIST_FILES=	bin/iiview
MAKE_JOBS_UNSAFE=	yes

MAN1=		iiview.1
MANCOMPRESSED=	yes
USE_BZIP2=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
