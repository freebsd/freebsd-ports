# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	scantailor
PORTVERSION=	0.9.11
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Scan Tailor is an interactive post-processing tool for scanned pages

LICENSE=	GPLv3

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		png15:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_CMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Scan Tailor" "Interactive post-processing tool for scanned pages" \
		"" "${PORTNAME}" "Graphics;Scanning;" false

.include <bsd.port.mk>
