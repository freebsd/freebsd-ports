# Created by: Mark Kane <mark@mkproductions.org>
# $FreeBSD$

PORTNAME=	streamtranscoder
PORTVERSION=	1.2.8
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://www.oddsock.org/tools/streamTranscoder/

MAINTAINER=	mark@mkproductions.org
COMMENT=	Transcode and stream audio to a SHOUTcast/Icecast/Peercast server

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libmad.so:${PORTSDIR}/audio/libmad \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libmp3lame.so:${PORTSDIR}/audio/lame

NO_STAGE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/streamTranscoder
PORTDOCS=	AUTHORS README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|g; \
		s|-pthread|${PTHREAD_LIBS}|g; s|-O20|$$CFLAGS|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/aclocal.m4 ${WRKSRC}/configure \
		${WRKSRC}/src/libtranscoder/transcurl.cpp

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
