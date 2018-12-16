# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yagf
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/yagf-ocr

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Graphical interface for an OCR program (tesseract)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libaspell.so:textproc/aspell

OPTIONS_DEFINE=TESSERACT
TESSERACT_DESC=		Tesseract OCR engine
TESSERACT_RUN_DEPENDS=	tesseract:graphics/tesseract

USES=		cmake desktop-file-utils pkgconfig qt:4
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT=		corelib gui imageformats linguist_build \
		moc_build qmake_build rcc_build uic_build

PLIST_FILES=	bin/yagf lib/yagf/libxspreload.so share/applications/YAGF.desktop\
		share/icons/hicolor/96x96/apps/yagf.png share/pixmaps/yagf.png
PORTDATA=	*

.include <bsd.port.mk>
