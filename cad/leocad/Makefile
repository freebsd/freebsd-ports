# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	leocad
PORTVERSION=	0.80.1
CATEGORIES=	cad
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz \
		${LEOCAD_PIECES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.tgz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	CAD program that uses bricks similar to those found in many toys

LICENSE=	GPLv2

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ldraw/models/car.dat:${PORTSDIR}/cad/ldraw

WRKSRC=		${WRKDIR}/${PORTNAME}
LEOCAD_PIECES=	pieces-7439.zip

USES=		desktop-file-utils gmake pkgconfig qmake shared-mime-info
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run \
		corelib gui network opengl

USE_GL=		glut
USE_GNOME=	gtk20

PORTDOCS=	CREDITS.txt README.txt TODO.txt

OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 24x24 32x32 48x48 128x128 256x256

post-extract:
	@${UNZIP_CMD} -q -o ${_DISTDIR}/${LEOCAD_PIECES} -d ${WRKDIR}/pieces

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		-e 's|share/man/man1|man/man1|' \
		${WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -e 's|docs.files = docs/README.txt docs/CREDITS.txt docs/COPYING.txt|docs.files = |' \
			 ${WRKSRC}/${PORTNAME}.pro

.for s in 16 24 32 48 128 256
	@cd ${WRKSRC}/tools/icon && \
		${MV} icon${s}.png ${PORTNAME}_${s}x${s}.png
.endfor
	@cd ${WRKSRC}/tools/icon && ${CP} -a ${PORTNAME}_128x128.png icon128.png
	@cd ${WRKSRC}/tools/icon && ${MV} icon.svg ${PORTNAME}.svg

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pieces/* ${STAGEDIR}${DATADIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/tools/icon/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/tools/icon/${PORTNAME}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	@${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/docs/leocad.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
