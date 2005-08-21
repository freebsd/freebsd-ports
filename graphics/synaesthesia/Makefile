# New ports collection makefile for:	synaesthesia
# Date created:				25 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	synaesthesia
PORTVERSION=	2.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.logarithmic.net/pfh-files/synaesthesia/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Graphically represents sound in real time

USE_SDL=	sdl
USE_GMAKE=	Yes
USE_REINPLACE=	Yes
USE_X_PREFIX=	Yes

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's,stdint.h,inttypes.h,' `${FIND} ${WRKSRC} -name \*.cc -or -name \*.c`
	@${REINPLACE_CMD} -e 's,int16_t,u_int16_t,' \
		-e 's,machine/soundcard.h,sys/soundcard.h,' ${WRKSRC}/sound.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/synaesthesia ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
