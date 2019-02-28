# $FreeBSD$

PORTNAME=	snzip
PORTVERSION=	1.0.4
CATEGORIES=	archivers

MAINTAINER=	mizhka@gmail.com
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

PLIST_FILES=	bin/snzip
PORTDOCS=	*

.include <bsd.port.mk>
