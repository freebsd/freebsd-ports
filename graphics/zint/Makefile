PORTNAME=	zint
PORTVERSION=	2.11.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Barcode generator (library and utilities)

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang cpe qt:5
USE_LDCONFIG=	yes
USE_QT=		buildtools_build qmake_build uitools_build core gui \
		svg widgets

DESKTOP_ENTRIES="Zint" "Barcode generator" "" "zint-qt" "" false

post-patch:
	@${REINPLACE_CMD} -e '/^add_library/s,STATIC,SHARED,' \
		${WRKSRC}/backend_qt/CMakeLists.txt

.include <bsd.port.mk>
