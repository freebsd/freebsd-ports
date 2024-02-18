PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.4.7
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Excel file reader/writer library using Qt
WWW=		https://qtexcel.github.io/QXlsx/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	QtExcel
GH_PROJECT=	QXlsx
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DQT_VERSION_MAJOR:STRING=${_QT_LIBVER}
WRKSRC_SUBDIR=	${GH_PROJECT}
PLIST_SUB=	QTVER=${_QT_LIBVER}

FLAVORS=	qt5 qt6

.if ${FLAVOR:U} == qt6
USES+=		qt:6
USE_QT=		base
PKGNAMESUFFIX=	-${FLAVOR}
.else
USES+=		qt:5
USE_QT=		buildtools:build qmake:build core gui
.endif

post-patch:
# Sanitize SOVERSION (we know about lack of ABI guarantees but don't care)
	@${REINPLACE_CMD} -E '/SOVERSION/s,([[:digit:]]+)\..*,\1,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
