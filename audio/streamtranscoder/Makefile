# Created by: Mark Kane <mark@mkproductions.org>
# $FreeBSD$

PORTNAME=	streamtranscoder
PORTVERSION=	1.2.8
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	http://BSDforge.com/projects/source/audio/streamtranscoder/

MAINTAINER=	mark@mkproductions.org
COMMENT=	Transcode and stream audio to a SHOUTcast/Icecast/Peercast server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libmad.so:audio/libmad \
		libcurl.so:ftp/curl \
		libmp3lame.so:audio/lame

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/streamTranscoder
PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O20|$$CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/aclocal.m4 ${WRKSRC}/configure \
		${WRKSRC}/src/libtranscoder/transcurl.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
