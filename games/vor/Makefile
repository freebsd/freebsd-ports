# New ports collection makefile for:	vor
# Date created:				07 Sep 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	vor
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://qualdan.com/vor/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Dodge the rocks until you die

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone

USE_SDL=	mixer image sdl
USE_BZIP2=	yes
USE_GMAKE=	yes

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/||' ${WRKSRC}/sound.c
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^\(my_objects.*\)$$|\1 ${LOCALBASE}/lib/libargp.a|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/vor|${DATADIR}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vor ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for d in *.png *.wav *.mod
	${INSTALL_DATA} ${WRKSRC}/data/${d} ${DATADIR}/
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
