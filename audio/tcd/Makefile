# New ports collection Makefile for:	tcd
# Date created:				20 June 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	tcd
PORTVERSION=	2.2.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A simple, user-friendly ncurses-based CD player

OPTIONS=	MUSICBRAINZ "Enable experimental MusicBrainz support" OFF

USE_SDL=	sdl
GNU_CONFIGURE=	yes

MAN1=	tcd.1
PLIST_FILES=	bin/tcd

.include <bsd.port.pre.mk>

.if defined(WITH_MUSICBRAINZ)
LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-DUSE_MUSICBRAINZ -lmusicbrainz -ggdb
post-patch:
	${REINPLACE_CMD} -e 's|tcd_SOURCES = |tcd_SOURCES = tcd_mb.c tcd_mb.h |' \
	    ${WRKSRC}/src/Makefile.am ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's|am_tcd_OBJECTS = |am_tcd_OBJECTS = tcd_mb.$$(OBJEXT) |' \
	    ${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.post.mk>
