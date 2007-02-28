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

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
USE_LDCONFIG=	yes

# For some reason this library contains config/ directory with
# lots of broken symlinks.  Remove them here and add new one using
# files/patch-config.  Files were taken from... Audacity, which is
# distributed with it's own version of SoundTouch ;-)
pre-patch:
	${RM} -rf ${WRKSRC}/config/*
	${FIND} ${WRKSRC} -name "Makefile.in*" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|; s|$$(prefix)/doc|$$(datadir)/doc|' \
		${WRKSRC}/source/example/bpm/Makefile.in \
		${WRKSRC}/source/example/SoundStretch/Makefile.in \
		${WRKSRC}/source/SoundTouch/Makefile.in \
		${WRKSRC}/include/Makefile.in ${WRKSRC}/Makefile.in
	# Fix for GCC 4.x
	${REINPLACE_CMD} -e 's|SoundTouch::||' ${WRKSRC}/include/SoundTouch.h
	${CHMOD} +rx ${WRKSRC}/config/install-sh
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
