# New ports collection makefile for:	synaesthesia
# Date created:				25 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	synaesthesia
PORTVERSION=	2.4
PORTREVISION=	3
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.logarithmic.net/pfh-files/synaesthesia/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphically represents sound in real time

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,stdint.h,inttypes.h,' ${WRKSRC}/*.c?
	@${REINPLACE_CMD} -e 's,int16_t,u_int16_t,' ${WRKSRC}/sound.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/synaesthesia ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
