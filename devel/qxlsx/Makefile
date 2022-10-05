PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.4.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Excel file reader/writer library using Qt
WWW=		https://qtexcel.github.io/QXlsx/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	QtExcel
GH_PROJECT=	QXlsx
USE_LDCONFIG=	yes
USE_QT=		buildtools:build qmake:build core gui

CMAKE_ON=	BUILD_SHARED_LIBS
WRKSRC_SUBDIR=	${GH_PROJECT}

.include <bsd.port.mk>
