# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	kye
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	http://games.moria.org.uk/kye/download/ \
		SF/nemysisfreebsdp/games/${PORTNAME}/:levels
# Selection of production-ready/well-known Kye Levels
# (Zipped levels already included from games.moria.org.uk are excluded)
# Please contact the maintainer if a Level is missing
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		kye-data_moria_levels.20121101.tar.gz:levels \
		kye-data_nuke_levels.20121101.tar.gz:levels \
		kye-data_extra_levels.20120818.tar.gz:levels
DIST_SUBDIR=	kye

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Puzzle game with arcade game elements

RESTRICTED=	kye-data_nuke_levels is charityware
RESTRICTED_FILES=	 kye-data_nuke_levels.20121101.tar.gz

USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Python Kye" "" "Kye" \
		"Kye" "Game;LogicGame;" ""

.include <bsd.port.options.mk>

post-extract-script:
	@${MKDIR} ${WRKDIR}/${PORTNAME}
.for l in kye-data_moria_levels.20121101.tar.gz kye-data_nuke_levels.20121101.tar.gz \
	kye-data_extra_levels.20120818.tar.gz
	${TAR} xfjp ${_DISTDIR}/${l} -C ${WRKDIR}/${PORTNAME}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/kye-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/Kye.png
	${INSTALL_DATA} ${WRKSRC}/kye-edit-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/Kye-edit.png
	@cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
