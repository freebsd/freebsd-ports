# Created by: ijliao
# $FreeBSD$

PORTNAME=	texmaker
PORTVERSION=	4.5
PORTREVISION=	16
PORTEPOCH=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX Development Environment

LICENSE=	GPLv2+

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		desktop-file-utils ghostscript:x11,run pkgconfig qmake qt:5 tar:bzip2
USE_QT=		concurrent network printsupport script webkit widgets \
		xml buildtools_build
USE_TEX=	latex dvipsk
EXTRACT_AFTER_ARGS=	--exclude hunspell
QMAKE_ARGS=	ICONDIR=${PREFIX}/share/pixmaps \
		DESKTOPDIR=${DESKTOPDIR}

.include <bsd.port.mk>
