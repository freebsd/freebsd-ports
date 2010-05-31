# New ports collection makefile for:	scantailor
# Date created:		2010-04-13
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	scantailor
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Scan Tailor is an interactive post-processing tool for scanned pages

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		png.6:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_CMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build

.include <bsd.port.mk>
