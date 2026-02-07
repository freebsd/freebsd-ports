PORTNAME=	iiview
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32
CATEGORIES=	graphics

MAINTAINER=	nakal@sugioarto.com
COMMENT=	Thumb viewer application
WWW=		https://github.com/nakal/iiview

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \

USES=		jpeg xorg
USE_XORG=	xpm x11

USE_GITHUB=	yes
GH_ACCOUNT=	nakal

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/iiview \
		share/man/man1/iiview.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/iiview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/src/iiview.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
