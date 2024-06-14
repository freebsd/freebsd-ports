PORTNAME=	taglookup
PORTVERSION=	0.2
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.kamaz.org.uk/taglookup/

MAINTAINER=	alex@kamaz.org.uk
COMMENT=	Utility for tagging groups of audio files using CDDB
WWW=		https://www.kamaz.org.uk/taglookup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, depends on legacy service that is defunct once again
EXPIRATION_DATE=2024-06-14

LIB_DEPENDS=	libcddb.so:audio/libcddb \
		libtag.so:audio/taglib

USES=		compiler:c++11-lang pkgconfig tar:tgz
USE_CXXSTD=	c++11

PLIST_FILES=	bin/taglookup \
		share/man/man1/taglookup.1.gz

.include <bsd.port.mk>
