# New ports collection makefile for:	trm
# Date created:				5 May 2003
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	trm
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
		ftp://ftp.nl.musicbrainz.org/ \
		ftp://ftp.au.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TRM generator to generate acoustic fingerprints

BUILD_DEPENDS=	madplay:${PORTSDIR}/audio/mad
LIB_DEPENDS=	musicbrainz.3:${PORTSDIR}/audio/libmusicbrainz \
		vorbisfile.4:${PORTSDIR}/audio/libvorbis

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
PLIST_FILES=	bin/trm

post-patch:
	@${REINPLACE_CMD} -e 's,-ldl,,g' ${WRKSRC}/configure

.include <bsd.port.mk>
