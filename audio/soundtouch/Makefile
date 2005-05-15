# New ports collection makefile for:	SoundTouch
# Date created:				16 May 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soundtouch
DISTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	http://sky.prohosting.com/oparviai/soundtouch/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open-source audio processing library

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/SoundTouch-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|; s|$$(prefix)/doc|$$(datadir)/doc|' \
		${WRKSRC}/source/example/bpm/Makefile.in \
		${WRKSRC}/source/example/SoundStretch/Makefile.in \
		${WRKSRC}/source/SoundTouch/Makefile.in \
		${WRKSRC}/include/Makefile.in ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/ install-pkgdocDATA$$//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
