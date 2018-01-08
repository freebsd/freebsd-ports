# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spacezero
PORTVERSION=	0.86.00
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION:R}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D Real Time Strategy space combat game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis

USES=		openal:al,alut pkgconfig
USE_GNOME=	gtk20
USE_XORG=	x11
LLD_UNSAFE=	yes
MAKE_ARGS=	DATADIR="${DATADIR}" \
		INSTALL_DATA_DIR="${DATADIR}"
ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

LDFLAGS+=	-lX11

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.ico

DESKTOP_ENTRIES="SpaceZero" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;StrategyGame;" \
		""

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1101000
post-patch:
	@${REINPLACE_CMD} -e 's|fdatasync|fsync|g' ${WRKSRC}/src/spacecomm.c
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/html/manual_files/space.ico ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/dat && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
