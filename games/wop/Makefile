# New ports collection makefile for:	wop
# Date created:		26 Dec 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	wop
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	http://wormsofprey.org/download/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Free real-time Worms game

USE_BZIP2=	yes
USE_SDL=	sdl net mixer ttf image
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ENV=	"CXX=${CXX}"

DATAVERSION=	2005-12-21

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on < 5.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|__va_copy|va_copy|g' ${WRKSRC}/src/string.cpp
	@${REINPLACE_CMD} -e 's|; make|; ${GMAKE}|g' ${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/sdlwidgets/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|= g++|?= g++|g' ${WRKSRC}/sdlwidgets/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|/etc/woprc|${PREFIX}/etc/woprc|' ${WRKSRC}/src/wopsettings.cpp
	@${REINPLACE_CMD} -e 's|\./data|${DATADIR}|' ${WRKSRC}/woprc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wop ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/woprc ${PREFIX}/etc

	@cd ${WRKDIR}/${PORTNAME}data-${DATAVERSION}; \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \; ; \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog README README-COMMAND-LINE-OPTIONS.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
