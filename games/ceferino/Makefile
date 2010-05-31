# New ports collection makefile for:	ceferino
# Date created:		2006-01-11
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	ceferino
PORTVERSION=	0.97.8
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/ceferino/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game similar to Super Pang

USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CEFEDIRS=	ima music levels sounds

OPTIONS=	NLS "Native Language Support"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
FLAG_NLS=	true
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/-lSDL /`sdl-config --libs`/g' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's/-pthread/-pthread -lintl/g' ${WRKSRC}/src/Makefile

do-install:
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} ceferino ceferinoeditor ceferinosetup ${PREFIX}/bin
	@cd ${WRKSRC}/data && \
		${FIND} ${CEFEDIRS} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} -E ${CEFEDIRS} -type f -iregex ".*\.(png|jpg|xm|map|wav)" -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if defined(FLAG_NLS)
.for f in es ca fr
	${MKDIR} ${PREFIX}/share/locale/${f}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/po/${f}.gmo ${PREFIX}/share/locale/${f}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
