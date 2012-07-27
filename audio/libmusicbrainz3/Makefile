# New ports collection makefile for:	libmusicbrainz3
# Date Created:				2007-05-17
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libmusicbrainz
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
		http://uk.musicbrainz.org/pub/musicbrainz/ \
		http://ftp.osuosl.org/pub/musicbrainz/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		neon:${PORTSDIR}/www/neon29

LATEST_LINK=	${PORTNAME}3

USE_CMAKE=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		-e '/CppUnit/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
