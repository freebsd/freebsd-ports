# Created by: ijliao
# $FreeBSD$

PORTNAME=	texmaker
PORTVERSION=	4.5
PORTREVISION=	10
PORTEPOCH=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX Development Environment

LICENSE=	GPLv2+

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell \
		libpoppler.so:graphics/poppler

USES=		desktop-file-utils ghostscript:x11,run pkgconfig qmake tar:bzip2
_USE_QT4=	gui network xml webkit \
		moc_build rcc_build uic_build
_USE_QT5=	concurrent network printsupport script webkit widgets \
		xml buildtools_build
USE_TEX=	latex dvipsk
EXTRACT_AFTER_ARGS=	--exclude hunspell
QMAKE_ARGS=	ICONDIR=${PREFIX}/share/pixmaps \
		DESKTOPDIR=${DESKTOPDIR}

OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT4_LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4
QT5_USE=	${_USE_QT5:S/^/QT5=/}
QT5_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

.include <bsd.port.mk>
