PORTNAME=	zint
PORTVERSION=	2.11.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Barcode generator (library and utilities)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang cpe qt:5
USE_LDCONFIG=	yes
USE_QT=		buildtools_build qmake_build uitools_build core gui \
		widgets xml

DESKTOP_ENTRIES="Zint" "Barcode generator" "" "zint-qt" "" false

post-patch:
	@${REINPLACE_CMD} -e '/^add_library/s,STATIC,SHARED,' \
		${WRKSRC}/backend_qt/CMakeLists.txt

.include <bsd.port.mk>
