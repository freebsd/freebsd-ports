PORTNAME=	libHX
PORTVERSION=	4.6
CATEGORIES=	lang
MASTER_SITES=	https://inai.de/files/libhx/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	C/C++ library with common data structures and functions

LICENSE=	LGPL21+

USES=		cpe libtool localbase tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CPE_VENDOR=	jan_engelhardt

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}

.include <bsd.port.mk>
