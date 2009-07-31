# New ports collection makefile for:	lcdtest
# Date created:			23 Mar 2007
# Whom:				Eric P. Scott <eps+pbug0703@ana.com>
#
# $FreeBSD$
#

PORTNAME=	lcdtest
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.brouhaha.com/~eric/software/lcdtest/download/ \
		CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LCD monitor test pattern generator

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm

USE_GMAKE=	yes
USE_SDL=	sdl image
CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	-o SDL/SDL.h -o SDL/SDL_image.h
PLIST_FILES=	bin/lcdtest
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS =/s|=|+=|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lcdtest ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
