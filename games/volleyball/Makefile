# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	volleyball
PORTVERSION=	0.8.6
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/volleyball/descargas/ \
		http://mirror.amdmi3.ru/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A game similar to GNU Arcade Volleyball

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USES=		gettext
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man" --disable-nls # strangeness in nls support
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README
MAN6=		volleyball.6

DATAVERSION=	0.8.5

DESKTOP_ENTRIES="Pocket Volleyball" \
		"A game similar to GNU Arcade Volleyball" \
		"" \
		"volleyball" \
		"Game;SportsGame;ArcadeGame;" \
		false

.include <bsd.port.options.mk>

post-configure:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-install:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
