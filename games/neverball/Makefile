# $FreeBSD$

PORTNAME=	neverball
PORTVERSION=	1.6.0
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/neverball/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tilt the floor to guide a ball through an obstacle course

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libphysfs.so:${PORTSDIR}/devel/physfs

USES=		gmake iconv
USE_GL=		gl
USE_SDL=	sdl2 ttf2
MAKE_ARGS+=	DATADIR="${DATADIR}" \
		LOCALEDIR="${PREFIX}/share/locale"

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
MAKE_ENV+=	ENABLE_NLS=1
.else
MAKE_ENV+=	ENABLE_NLS=0
.endif

do-install:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${INSTALL_MAN} ${WRKSRC}/dist/*.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
.for f in neverball neverputt
	${INSTALL_DATA} ${WRKSRC}/dist/${f}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/dist/${f}_512.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${f}.png
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/locale && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/locale/
.endif
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
