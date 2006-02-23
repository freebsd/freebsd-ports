# New ports collection makefile for:	musicbrainz
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2nd generation incarnation of the CD Index - audio metadata

CONFLICTS=	libmusicbrainz-*

BROKEN=		Does not build
DEPRECATED=	Surpassed by audio/libmusicbrainz
EXPIRATION_DATE=2006-03-14

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CPPFLAGS=|#CPPFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
