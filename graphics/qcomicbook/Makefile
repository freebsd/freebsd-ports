# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	QComicBook
PORTVERSION=	0.9.1
PORTREVISION=	10
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-based comic book archive viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		cmake compiler:c++11-lang pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	stolowski
USE_QT=		core gui printsupport widgets x11extras\
		buildtools_build linguisttools_build qmake_build

OPTIONS_DEFINE=	7ZIP ACE RAR

7ZIP_DESC=	7-Zip (.cb7) comic book archives support
7ZIP_RUN_DEPENDS=	7z:archivers/p7zip

ACE_DESC=	ACE (.cba) comic book archives support
ACE_RUN_DEPENDS=	unace:archivers/unace

RAR_DESC=	Rar (.cbr) comic book archives support
RAR_RUN_DEPENDS=	unrar:archivers/unrar

.include <bsd.port.mk>
