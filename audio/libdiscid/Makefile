PORTNAME=	libdiscid
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/metabrainz/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		http://ftp.osuosl.org/pub/musicbrainz/${PORTNAME}/ \
		http://ftp.eu.metabrainz.org/pub/musicbrainz/${PORTNAME}/

PATCH_SITES=	https://github.com/metabrainz/libdiscid/commit/
PATCHFILES=	b89c14599fd8798eef64431bb05e8705aaaea683.patch:-p1 #Fix pkgconfig file (PR: 269990)

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for creating MusicBrainz DiscIDs
WWW=		https://musicbrainz.org/doc/libdiscid

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pathfix
USE_LDCONFIG=	yes

# Full test requires an audio CD to be in the drive
TEST_TARGET=	check

.include <bsd.port.mk>
