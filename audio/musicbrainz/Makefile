# New ports collection makefile for:	musicbrainz
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	1.0.0.pre6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/
DISTNAME=	${PORTNAME}-1.0.0pre6

MAINTAINER=	roman@xpert.com

USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

pre-extract:
.if !defined(WITHOUT_VORBIS)
	@${ECHO}
	@${ECHO} "You can disable Vorbis support by defining WITHOUT_VORBIS"
	@${ECHO}
LIB_DEPENDS+=	vorbis.0:${PORTSDIR}/audio/libvorbis
HAVE_VORBIS=	yes
.endif

post-extract:
	${TOUCH} ${WRKSRC}/stamp-h.in

.include <bsd.port.mk>
