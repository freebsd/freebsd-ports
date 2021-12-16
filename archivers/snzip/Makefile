PORTNAME=	snzip
PORTVERSION=	1.0.5
CATEGORIES=	archivers
DISTVERSIONPREFIX= v

MAINTAINER=	mizhka@freebsd.org
COMMENT=	Compression/decompression tool based on snappy library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsnappy.so:archivers/snappy

OPTIONS_DEFINE=	DOCS

USES=		autoreconf compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	kubo

CONFIGURE_ARGS=	--with-snappy=${LOCALBASE}
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/snunzip \
                bin/snzcat \
                bin/snzip

PORTDOCS=	*

.include <bsd.port.mk>
