# ex:ts=8
# New ports collection makefile for:	ksmp3play
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ksmp3play
PORTVERSION=	0.5.1
CATEGORIES=	audio
MASTER_SITES=	http://www.xanadunet.net/ksmp3play/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An curses-based MP3 player

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_REINPLACE=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG} \
		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	ksmp3play.1

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude "CVS" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
