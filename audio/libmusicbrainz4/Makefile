# New ports collection makefile for:	libmusicbrainz4
# Date Created:				2007-05-17
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libmusicbrainz4
PORTVERSION=	4.0.3
CATEGORIES=	audio
MASTER_SITES=	https://cloud.github.com/downloads/metabrainz/${PORTNAME:S/4//}/
DISTNAME=	${PORTNAME:S/4//}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	MusicBrainz client library for audio metadata lookup

LICENSE=	LGPL21

LIB_DEPENDS=	neon:${PORTSDIR}/www/neon29

USE_CMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

MAKE_JOBS_SAFE=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		 ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
