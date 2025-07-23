PORTNAME=	libdiscid
PORTVERSION=	0.6.5
CATEGORIES=	audio
MASTER_SITES=	https://github.com/metabrainz/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		http://ftp.osuosl.org/pub/musicbrainz/${PORTNAME}/ \
		http://ftp.eu.metabrainz.org/pub/musicbrainz/${PORTNAME}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for creating MusicBrainz DiscIDs
WWW=		https://musicbrainz.org/doc/libdiscid

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_LDCONFIG=	yes

# Full test requires an audio CD to be in the drive
TEST_TARGET=	check

.include <bsd.port.mk>
