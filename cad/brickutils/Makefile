# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brickutils
PORTVERSION=	0.1.6.1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	BrickUtils-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Utility for building models with LEGO

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/ldraw/models/car.dat:${PORTSDIR}/cad/ldraw \
		${PYTHON_PACKAGENAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYXML}

WRKSRC=		${WRKDIR}/BrickUtils-${PORTVERSION}

USE_GNOME=	pygtk2
USE_PYTHON=	yes

PORTDOCS=	ChangeLog
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} \
		pkg-message

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}|' \
		${WRKSRC}/pyBrickUtils.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for f in pyBrickUtils.py pyBrickUtils.pyc pyBrickUtils.pyo catalog.new
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DATADIR})
.endfor
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} BrickUtils ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/BrickUtils.desktop ${STAGEDIR}${DESKTOPDIR}
	@${CHMOD} -R 775 ${STAGEDIR}${DATADIR}
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 664 catalog.new)

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
