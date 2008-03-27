# New ports collection makefile for:	libmusicbrainz3
# Date Created:				2007-05-17
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libmusicbrainz3
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
    		http://uk.musicbrainz.org/pub/musicbrainz/
DISTNAME=	${PORTNAME:S/3//}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	MusicBrainz client library for audio metadata lookup

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		neon.26:${PORTSDIR}/www/neon

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

pre-configure:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}\/pkgconfig|libdata\/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

do-configure:
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS})

.include <bsd.port.post.mk>
