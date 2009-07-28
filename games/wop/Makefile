# New ports collection makefile for:	wop
# Date created:		26 Dec 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	wop
PORTVERSION=	0.4.3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://wormsofprey.org/download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free real-time Worms game

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_BZIP2=	yes
USE_SDL=	sdl net mixer ttf image
USE_GMAKE=	yes

MAKE_ENV=	"CXX=${CXX}"

DATAVERSION=	2005-12-21

post-patch:
	@${REINPLACE_CMD} -e 's|__va_copy|va_copy|g' ${WRKSRC}/src/string.cpp
	@${REINPLACE_CMD} -e 's|; make|; ${GMAKE}|g' ${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/sdlwidgets/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|= g++|?= g++|g' ${WRKSRC}/sdlwidgets/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|/etc/woprc|${PREFIX}/etc/woprc|' ${WRKSRC}/src/wopsettings.cpp
	@${REINPLACE_CMD} -e 's|\./data|${DATADIR}|' ${WRKSRC}/woprc
	@${REINPLACE_CMD} -e '/stdint.h/ d' ${WRKSRC}/src/attachableobject.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wop ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/woprc ${PREFIX}/etc/woprc.sample
	if [ ! -f ${PREFIX}/etc/woprc ]; then \
		${INSTALL_DATA} ${WRKSRC}/woprc ${PREFIX}/etc; \
	fi

	@echo "Installing data files..."
	@cd ${WRKDIR}/${PORTNAME}data-${DATAVERSION}; \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \; ; \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog README README-COMMAND-LINE-OPTIONS.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
