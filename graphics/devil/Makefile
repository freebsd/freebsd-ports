# New ports collection makefile for:   devil
# Date created:        8 August 2004
# Whom:                Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	devil
PORTVERSION=	1.6.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openil
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A full featured cross-platform image library

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		mng.1:${PORTSDIR}/graphics/libmng \
		lcms.1:${PORTSDIR}/graphics/lcms

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.mk>
