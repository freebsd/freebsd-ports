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
USES=	tar:bzip2

PLIST_FILES=	bin/iiview man/man1/iiview.1.gz

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
