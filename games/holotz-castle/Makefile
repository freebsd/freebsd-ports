# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	holotz-castle
PORTVERSION=	1.3.14
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform game with high doses of mystery

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

USES=		desthack gl gmake gnome sdl
USE_CXXSTD=	c++98
USE_GL=		gl
USE_SDL=	image mixer sdl ttf
MAKE_ARGS=	HC_BASE=${PREFIX}/share/${PORTNAME}/ \
		HC_BIN_DIR=${PREFIX}/bin/
MAKE_JOBS_UNSAFE=	yes

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

SUB_FILES=	pkg-message ${PORTNAME}-solutions

PORTDATA=	*

OPTIONS_DEFINE=	SOLUTIONS
OPTIONS_DEFAULT=SOLUTIONS
SOLUTIONS_DESC=	Solutions for Holotz's Castle

OPTIONS_SUB=	yes

SOLUTIONS_RUN_DEPENDS=	mplayer:multimedia/mplayer

SOLUTIONS_DISTFILES=	${PORTNAME}_solutions${EXTRACT_SUFX}
SOLUTIONS_EXTRACT_ONLY=	${PORTNAME}_solutions${EXTRACT_SUFX}

post-install:
.for f in ${PORTNAME} ${PORTNAME}-editor
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${f} ${STAGEDIR}${PREFIX}/bin/)
.endfor
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/man && ${INSTALL_MAN} *.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/)

post-install-SOLUTIONS-on:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-solutions ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}-solutions.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/solutions
	@(cd ${WRKDIR} && ${INSTALL_DATA} *.avi ${STAGEDIR}${DATADIR}/solutions)

.include <bsd.port.mk>
