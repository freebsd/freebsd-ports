# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	xye
PORTVERSION=	0.12.1
CATEGORIES=	games
MASTER_SITES=	SF:game \
		http://xye.sourceforge.net/levels/ \
		http://xye.sourceforge.net/:xmas \
		SF/nemysisfreebsdp/:nemysis \
		http://xye.sourceforge.net/skins/:skins
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:game \
		${LEVELS:S/$/.zip/} \
		${LEVELS_XYE:S/$/.xye/} \
		xmas-xye-2009.zip:xmas \
		xye_extra_levels.20121109.zip:nemysis \
		XMASKYESKIN.zip:skins \
		Xye%20skin%20-%20classic%20kye.zip:skins
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${LEVELS:S/$/.zip/} \
		xmas-xye-2009.zip \
		xye_extra_levels.20121109.zip \
		${SKINS:S/$/.zip/}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Puzzle games like sokoban or boulderdash

LICENSE=	ZLIB

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_SDL=	sdl image ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${PREFIX}/share/doc
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

LEVELS=		Xye%20level%20-%20Open%20Ended Xye%20level%20-%20Sorting \
		Xye%20level%20-%20The%20insider Xye%20level%20-%20The%20slow%20speedrun \
		Xye%20level%20-%20disturbingarrows Xye%20level%20-%20Duels%20of%20fate \
		nuffmagnets Xye%20levels%20-%20Pyramid%20treasure afirflood \
		Xye%20level%20-%20Blob%20prison Xye%20levels%20-%20ActionReplay \
		Xye%20level%20-%20gravity Xye%20level%20-%20pluzze

LEVELS_XYE=	dungeon turnaround chekhov

SKINS=		XMASKYESKIN Xye%20skin%20-%20classic%20kye

DESKTOP_ENTRIES="Xye" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ${FALSE}

SUB_FILES=	 pkg-message

OPTIONS_DEFINE=	DOCS SKINS
OPTIONS_DEFAULT=	SKINS
SKINS_DESC=	Install additional skins

.include <bsd.port.options.mk>

.if defined(WITH_SKINS)
PLIST_SUB+=	SKINS=""
.else
PLIST_SUB+=	SKINS="@comment "
.endif

post-extract-script:
.for l in ${LEVELS:S/$/.zip/} xmas-xye-2009.zip xye_extra_levels.20121109.zip
	@${UNZIP_CMD} -qoj -d ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${l}
.endfor

.if ${PORT_OPTIONS:MSKINS}
.  for s in ${SKINS:S/$/.zip/}
	@${UNZIP_CMD} -qoj -d ${WRKDIR}/skins ${DISTDIR}/${DIST_SUBDIR}/${s}
.  endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|docedir = $$(datadir)|docedir = ${PREFIX}/share/doc|' \
		${WRKSRC}/Makefile.in

.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} '/install-data-am:/s/install-doceDATA//' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "*.xye *.txt" ${DATADIR}/levels

.if ${PORT_OPTIONS:MSKINS}
	@cd ${WRKDIR}/skins && ${COPYTREE_SHARE} \* ${DATADIR}/res
.endif

	${LN} -sf ${DATADIR}/res/detailed_icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
