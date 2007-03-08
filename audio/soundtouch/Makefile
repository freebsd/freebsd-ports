# New ports collection makefile for:	SoundTouch
# Date created:				16 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soundtouch
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open-source audio processing library

BUILD_DEPENDS=	${LOCALBASE}/bin/automake19:${PORTSDIR}/devel/automake19
CONFIGURE_ARGS=	--enable-shared=yes
USE_AUTOTOOLS=	autoconf:259 libtool:15
USE_LDCONFIG=	yes

post-patch: .SILENT
.for f in config.guess config.sub depcomp install-sh missing
	${LN} -sf ${LOCALBASE}/share/automake19/${f} ${WRKSRC}/config/${f}
.endfor
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g; \
		s|-O3|${CFLAGS}|; s|$$(prefix)/doc|$$(datadir)/doc|; \
		s|COPYING.TXT||'
	# Fix for GCC 4.x
	${REINPLACE_CMD} -e 's|SoundTouch::||' ${WRKSRC}/include/SoundTouch.h
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's| install-pkgdocDATA$$||' \
		${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
