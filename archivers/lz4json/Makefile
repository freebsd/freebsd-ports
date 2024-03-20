PORTNAME=	lz4json
PORTVERSION=	20191229
PORTREVISION=	1
CATEGORIES=	archivers www

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Unpack Mozilla lz4json files, such as bookmarks and session restore
WWW=		https://github.com/andikleen/lz4json

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	andikleen
GH_TAGNAME=	c44c5100
PLIST_FILES=	bin/lz4jsoncat share/man/man1/lz4jsoncat.1${COMPRESS_EXT}

MAKEFILE=	${FILESDIR}/BSDmakefile

.include <bsd.port.mk>
