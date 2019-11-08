# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	xye
PORTVERSION=	0.12.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF:game \
		http://xye.sourceforge.net/levels/ \
		http://xye.sourceforge.net/:xmas \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:nemysis \
		http://xye.sourceforge.net/skins/:skins
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:game \
		${LEVELS:S/$/.zip/} \
		${LEVELS_XYE:S/$/.xye/} \
		xmas-xye-2009.zip:xmas \
		xye_extra_levels.20121109.zip:nemysis \
		Xye%20skin%20-%20classic%20kye.zip:skins \
		XMASKYESKIN.zip:skins
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle games like sokoban or boulderdash

LICENSE=	ZLIB

EXTRACT_DEPENDS=${UNZIP_CMD}:archivers/unzip

USES=		compiler gmake sdl
USE_SDL=	sdl image ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${PREFIX}/share/doc
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

LEVELS=		Xye%20level%20-%204corners Xye%20level%20-%20Against%20the%20force \
		Xye%20level%20-%20Stop%20that%20cab Xye%20level%20-%20Helping%20Hand \
		Xye%20level%20-%20The%20plan Xye%20level%20-%20Controller \
		Xye%20level%20-%20At%20once Xye%20level%20-%20Open%20Ended \
		Xye%20level%20-%20Sorting Xye%20level%20-%20The%20insider \
		Xye%20level%20-%20The%20slow%20speedrun Xye%20levels%20-%20SuperJustin \
		Xye%20level%20-%20disturbingarrows Xye%20level%20-%20Duels%20of%20fate \
		nuffmagnets Xye%20levels%20-%20Pyramid%20treasure afirflood \
		Xye%20level%20-%20Blob%20prison Xye%20levels%20-%20ActionReplay \
		Xye%20level%20-%20gravity Xye%20level%20-%20pluzze

LEVELS_XYE=	dungeon turnaround chekhov

SKINS=		Xye%20skin%20-%20classic%20kye XMASKYESKIN

PORTDOCS=	*

DESKTOP_ENTRIES="Xye" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" false

SUB_FILES=	 pkg-message

OPTIONS_DEFINE=	DOCS SKINS
OPTIONS_DEFAULT=	SKINS
SKINS_DESC=	Install additional skins

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-extract-script:
.for l in ${LEVELS:S/$/.zip/} xmas-xye-2009.zip xye_extra_levels.20121109.zip
	@${UNZIP_CMD} -qoj -d ${WRKDIR} ${_DISTDIR}/${l}
.endfor

.if ${PORT_OPTIONS:MSKINS}
.  for s in ${SKINS:S/$/.zip/}
	@${UNZIP_CMD} -qoj -d ${WRKDIR}/skins ${_DISTDIR}/${s}
.  endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|docedir = $$(datadir)|docedir = ${PREFIX}/share/doc|' \
		${WRKSRC}/Makefile.in

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} '/install-data-am:/s/install-doceDATA//' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} "*.xye *.txt" ${STAGEDIR}${DATADIR}/levels)

.if ${PORT_OPTIONS:MSKINS}
	@(cd ${WRKDIR}/skins && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/res)
.endif

	${RLN} ${STAGEDIR}${DATADIR}/res/detailed_icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
