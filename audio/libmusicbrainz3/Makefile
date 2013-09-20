# $FreeBSD$

PORTNAME=	libmusicbrainz
PORTVERSION=	3.0.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
		http://ftp.osuosl.org/pub/musicbrainz/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		neon:${PORTSDIR}/www/neon29

LATEST_LINK=	${PORTNAME}3

USES=		cmake
NO_STAGE=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		-e '/CppUnit/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

.include <bsd.port.mk>
