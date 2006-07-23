# New ports collection makefile for:	aqbubble
# Date created:		2006-04-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	aqbubble
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/juegos/aqbubble/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game similar to snow bros

USE_X_PREFIX=	yes
USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

AQBUBBLEDIRS=	ima sonidos

OPTIONS=	NLS "Native Language Support"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-extract:
	@${FIND} -E ${WRKSRC}/src/ -type f -iregex ".*\.(cpp|h)" \
		-print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's/<SDL/<SDL11/'
	@${REINPLACE_CMD} -e 's/-lSDL /`sdl11-config --libs`/g' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's/-lSDL /`sdl11-config --libs` -lintl /g' ${WRKSRC}/src/Makefile

do-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} aqbubble  ${PREFIX}/bin && \
			${FIND} ${AQBUBBLEDIRS} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
				${FIND} -E ${AQBUBBLEDIRS} -type f -iregex ".*\.(png|jpg|wav)" \
					-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.if !defined(WITHOUT_NLS)
.for FILE in es
	${MKDIR} ${PREFIX}/share/locale/${FILE}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/po/${FILE}.gmo ${PREFIX}/share/locale/${FILE}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
