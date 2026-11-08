PORTNAME=	QComicBook
PORTVERSION=	0.10.0
CATEGORIES=	graphics

MAINTAINER=	kenrap@FreeBSD.org
COMMENT=	Qt-based comic book archive viewer
WWW=		https://github.com/stolowski/QComicBook

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-qt6.so:graphics/poppler-qt6

USES=		cmake compiler:c++17-lang desktop-file-utils pkgconfig qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	valepert

USE_QT=		base tools:build

OPTIONS_DEFINE=	7ZIP ACE RAR

7ZIP_DESC=		7-Zip (.cb7) comic book archives support
7ZIP_RUN_DEPENDS=	7zz:archivers/7-zip

ACE_DESC=		ACE (.cba) comic book archives support
ACE_RUN_DEPENDS=	unace:archivers/unace

RAR_DESC=		Rar (.cbr) comic book archives support
RAR_RUN_DEPENDS=	unrar:archivers/unrar

.include <bsd.port.mk>
