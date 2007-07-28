# New ports collection makefile for:	SoundTouch
# Date created:				16 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soundtouch
DISTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open-source audio processing library

CONFIGURE_ARGS=	--enable-shared=yes
USE_AUTOTOOLS=	autoconf:259 automake:19:env libtool:15
USE_LDCONFIG=	yes

BROKEN=		Does not compile

post-patch: .SILENT
.for f in config.guess config.sub depcomp install-sh missing
	${LN} -sf ${LOCALBASE}/share/automake-1.9/${f} ${WRKSRC}/config/${f}
.endfor
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g; \
		s|-O3[^I]*|${CXXFLAGS} -|; s|$$(prefix)/doc|$$(datadir)/doc|; \
		s|COPYING.TXT||'
# Fix for GCC 4.x
	${REINPLACE_CMD} -e 's|SoundTouch::||' ${WRKSRC}/include/SoundTouch.h
# Better SSE detection
	${REINPLACE_CMD} -e '135s|__x86_64__|&) \&\& defined(__SSE__|' \
		${WRKSRC}/include/STTypes.h
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's| install-pkgdocDATA$$||' \
		${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
