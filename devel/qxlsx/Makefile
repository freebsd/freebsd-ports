PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.4.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	8e83402db866ae7a67582da28aa68c83545f13c8.patch:-p2

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
