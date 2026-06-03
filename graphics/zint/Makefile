PORTNAME=	zint
PORTVERSION=	2.16.0
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

DESKTOP_ENTRIES="Zint" "Barcode generator" "zint-qt" "zint-qt" "" false
PLIST_SUB+=	VER=${PORTVERSION:R}
PORTDOCS=	ChangeLog README TODO manual.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^add_library/s,STATIC,SHARED,' \
		${WRKSRC}/backend_qt/CMakeLists.txt

# XXX: in lieu of addressing ``project(zint-package)'' stupidity
post-stage: ; @${RMDIR} ${STAGEDIR}${DOCSDIR}-package

.include <bsd.port.mk>
