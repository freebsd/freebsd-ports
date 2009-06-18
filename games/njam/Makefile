# New ports collection makefile for: njam
# Date created:		10 November 2003
# Whom:			<janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	njam
PORTVERSION=	1.25
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast paced multiplayer pac-man clone

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -D__linux__"
USE_SDL=	mixer image net sdl
MAKE_JOBS_SAFE=	yes
PORTDOCS=	*

post-extract:
	@${RM} -f ${WRKSRC}/src/*.o

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/games|/var/games|' \
		${WRKSRC}/src/njam.cpp

post-install:
	${CHOWN} :games ${PREFIX}/bin/njam
	${CHMOD} g+s ${PREFIX}/bin/njam
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
