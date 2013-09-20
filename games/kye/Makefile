# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	kye
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	http://games.moria.org.uk/kye/download/ \
		SF/nemysisfreebsdp/kye/:nemysis
# Selection of production-ready/well-known Kye Levels
# (Zipped levels already included from games.moria.org.uk are excluded)
# Please contact the maintainer if a Level is missing
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		kye-data_moria_levels.20121101.tar.gz:nemysis \
		kye-data_nuke_levels.20121101.tar.gz:nemysis \
		kye-data_extra_levels.20120818.tar.gz:nemysis
DIST_SUBDIR=	kye

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Puzzle game with arcade game elements

LICENSE=	GPLv2

USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_BUILD=	yes

PORTDOCS=	NEWS README

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Python Kye" "${COMMENT}" "Kye" \
		"Kye" "Game;LogicGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract-script:
	${MKDIR} ${WRKDIR}/${PORTNAME}
.for l in kye-data_moria_levels.20121101.tar.gz kye-data_nuke_levels.20121101.tar.gz kye-data_extra_levels.20120818.tar.gz
	${TAR} xfjp ${DISTDIR}/${DIST_SUBDIR}/${l} -C ${WRKDIR}/${PORTNAME}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/kye-icon.png ${PREFIX}/share/pixmaps/Kye.png
	${INSTALL_DATA} ${WRKSRC}/kye-edit-icon.png ${PREFIX}/share/pixmaps/Kye-edit.png
	@cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} \* ${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
