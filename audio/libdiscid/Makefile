PORTNAME=	libdiscid
PORTVERSION=	0.6.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/${PORTNAME}/ \
		http://ftp.osuosl.org/pub/musicbrainz/${PORTNAME}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for creating MusicBrainz DiscIDs

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pathfix
USE_LDCONFIG=	yes

# Full test requires an audio CD to be in the drive
TEST_TARGET=	check

.include <bsd.port.mk>
