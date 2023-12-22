PORTNAME=	zint
PORTVERSION=	2.13.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Barcode generator (library and utilities)
WWW=		https://www.zint.org.uk/

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang cpe qt:5
USE_LDCONFIG=	yes
USE_QT=		buildtools:build qmake:build uitools:build core gui \
		svg widgets

DESKTOP_ENTRIES="Zint" "Barcode generator" "" "zint-qt" "" false
PLIST_SUB+=	VER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e '/^add_library/s,STATIC,SHARED,' \
		${WRKSRC}/backend_qt/CMakeLists.txt

.include <bsd.port.mk>
