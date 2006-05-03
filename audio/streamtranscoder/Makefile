# New ports collection makefile for:	streamtranscoder
# Date created:				29 August 2005
# Whom:					Mark Kane <mark@mkproductions.org>
#
# $FreeBSD$
#

PORTNAME=	streamtranscoder
PORTVERSION=	1.2.8
CATEGORIES=	audio
MASTER_SITES=	http://www.oddsock.org/tools/streamTranscoder/

MAINTAINER=	mark@mkproductions.org
COMMENT=	Transcode and stream audio to a SHOUTcast/Icecast/Peercast server

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		mad:${PORTSDIR}/audio/libmad \
		curl:${PORTSDIR}/ftp/curl \
		mp3lame:${PORTSDIR}/audio/lame

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/streamTranscoder
PORTDOCS=	AUTHORS README

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|g; \
		s|-pthread|${PTHREAD_LIBS}|g; s|-O20|$$CFLAGS|g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
