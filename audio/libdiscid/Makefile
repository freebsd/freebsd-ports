PORTNAME=	libdiscid
DISTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/metabrainz/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://data.musicbrainz.org/pub/musicbrainz/${PORTNAME}/

PATCH_SITES=	https://github.com/metabrainz/${PORTNAME}/commit/
PATCHFILES+=	d9e81a9a8af7679733907418a340c50e9fec8023.patch:-p1 # Use HTTPS for MusicBrainz URLs

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
