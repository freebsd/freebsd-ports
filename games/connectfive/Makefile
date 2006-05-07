# New ports collection makefile for:	connectfive
# Date created:			20 Sep 2005
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	connectfive
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	connectfive
DISTNAME=	connectFive

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Place five pieces in a row on a 3d board

MAKEFILE=	Makefile.linux
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
			CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
ALL_TARGET=	default

USE_SDL=	sdl
USE_GL=		yes
USE_GMAKE=	yes

WRKSRC=	${WRKDIR}/connectFive

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/*.cpp ${WRKSRC}/*.h
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.linux
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/connect.cpp

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/connectfive ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.txt ${WRKSRC}/LICENSE.txt ${WRKSRC}/README.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
