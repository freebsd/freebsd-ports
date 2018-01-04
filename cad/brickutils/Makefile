# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brickutils
PORTVERSION=	0.1.6.1
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}-obsolete/ \
		SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}-obsolete/:docs \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	BrickUtils-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	BrickUtils-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}

MAINTAINER=	koalative@gmail.com
COMMENT=	Utility for building models with LEGO

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/ldraw/models/car.dat:cad/ldraw \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

WRKSRC=		${WRKDIR}/BrickUtils-${PORTVERSION}

NO_ARCH=	yes
USES=		python:2 shebangfix
USE_GNOME=	pygtk2
SHEBANG_FILES=	pyBrickUtils.py \
		BrickUtils/*.py

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ChangeLog
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME} \
		pkg-message

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DOCS_DISTFILES=	${PORTNAME}-manual-it.pdf:docs \
		${PORTNAME}-manual.pdf:docs

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
	${LN} -sf ../icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@(cd ${_DISTDIR} && ${CP} -a *.pdf ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
