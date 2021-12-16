PORTNAME=	snzip
PORTVERSION=	1.0.5
DISTVERSIONPREFIX= v
CATEGORIES=	archivers

MAINTAINER=	mizhka@freebsd.org
COMMENT=	Compression/decompression tool based on snappy library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsnappy.so:archivers/snappy

USES=		autoreconf compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	kubo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-snappy=${LOCALBASE}

PLIST_FILES=	bin/snunzip \
		bin/snzcat \
		bin/snzip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
