# $FreeBSD$

PORTNAME=	neverball
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/neverball/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tilt the floor to guide a ball through an obstacle course

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libphysfs.so:devel/physfs

USES=		gmake iconv jpeg
USE_GL=		gl
USE_SDL=	sdl2 ttf2
MAKE_ARGS+=	DATADIR="${DATADIR}" \
		LOCALEDIR="${PREFIX}/share/locale"

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
NLS_MAKE_ENV_ON=	ENABLE_NLS=1
NLS_MAKE_ENV_OFF=	ENABLE_NLS=0

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

do-install-NLS-on:
	cd ${WRKSRC}/locale && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/locale/

do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
