# New ports collection makefile for:	SoundTouch
# Date created:				16 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soundtouch
DISTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open-source audio processing library

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
USE_LDCONFIG=	yes
PORTDOCS=	README.html

post-patch: .SILENT
# Adjust some paths for FreBSD, respect CFLAGS, and get rid of GPL
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E \
		's|\(libdir\)/pkgconfig|(prefix)/libdata/pkgconfig|g; \
		s| -O3( -[mf][[:graph:]]*)*||; \
		s|\(prefix\)/doc|(datadir)/doc|; s|COPYING\.TXT||'
# Fix SSE detection
	${REINPLACE_CMD} -e 's|__x86_64__|&) \&\& defined(__SSE__|' \
		${WRKSRC}/include/STTypes.h
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|[[:blank:]]install-pkgdocDATA$$||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
