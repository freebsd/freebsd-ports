# New ports collection makefile for:	linux-goodway
# Date created:				25 Nov 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-goodway
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://www.xpgoodwayteam.org/dwn_goodway/
DISTNAME=	goodwayv${GWVERSION}_free

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A flight planner for the X-Plane flight simulator

BUILD_DEPENDS=	icoconvert:${PORTSDIR}/graphics/icoconvert
RUN_DEPENDS=	X-Plane:${PORTSDIR}/games/linux-x-plane

WRKSRC=		${WRKDIR}/GoodWay${GWVERSION}F
USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_LINUX=	yes
RESTRICTED=	"Redistribution prohibited"
ONLY_FOR_ARCHS=	i386

GWVERSION=	${PORTVERSION:S|.||g}

XDIR=		${X11BASE}/lib/x-plane
GWDIR=		${PREFIX}/lib/goodway
GWDIR_REL=	${GWDIR:S,^${PREFIX}/,,}

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/goodway share/pixmaps/goodway.png
PLIST_DIRS=	${GWDIR_REL}

SUB_FILES=	goodway
SUB_LIST=	GWDIR="${GWDIR}" PORTVERSION="${PORTVERSION}"

DESKTOP_ENTRIES="GoodWay" \
		"Manage flight plans" \
		"goodway.png" \
		"goodway" \
		"Application;Game;" \
		false

post-patch:
	@${MKDIR} ${WRKSRC}/.scripts
	@${MV} ${WRKSRC}/goodway ${WRKSRC}/.scripts
	@${MKDIR} ${WRKSRC}/.scripts/JRE/bin
	@${MV} ${WRKSRC}/JRE/bin/ControlPanel ${WRKSRC}/.scripts/JRE/bin
	@${MKDIR} ${WRKSRC}/.scripts/JRE/javaws
	@${MV} ${WRKSRC}/JRE/javaws/javaws ${WRKSRC}/.scripts/JRE/javaws
	@${MKDIR} ${WRKSRC}/.programs/JRE/bin
	@${MV} ${WRKSRC}/JRE/bin/* ${WRKSRC}/.programs/JRE/bin
	@${MKDIR} ${WRKSRC}/.programs/JRE/javaws
	@${MV} ${WRKSRC}/JRE/javaws/javawsbin ${WRKSRC}/.programs/JRE/javaws

do-build:
	@${ECHO_CMD} 'GNL_XPlaneEXE=${X11BASE}/lib/x-plane/X-Plane-816-lin1-i586' > ${WRKSRC}/Properties3.prf
	@${ECHO_CMD} 'GNL_XPlaneDir=${X11BASE}/lib/x-plane' >> ${WRKSRC}/Properties3.prf
	@icoconvert ${WRKSRC}/ICON1.ICO
	@${MKDIR} ${WRKSRC}/.icons
	@${MV} ${WRKSRC}/ICON1_*.png ${WRKSRC}/.icons

pre-install:
	@${RM} -f ${PLIST}
	@${RM} -f ${PLIST}.dirs
.for d in "" .programs .scripts
	@cd ${WRKSRC}/${d} && \
	${FIND} * -type f | ${SORT} | ${SED} -e 's|^|${GWDIR_REL}/|' >> ${PLIST} && \
	${FIND} * -type d >> ${PLIST}.dirs
.endfor
	@${SORT} -ru ${PLIST}.dirs | ${SED} -e 's|^|@dirrm ${GWDIR_REL}/|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/goodway ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/.icons/ICON1_48X48_32bpp.png ${PREFIX}/share/pixmaps/goodway.png
.for d in "" .programs .scripts
	cd ${WRKSRC}/${d} && ${FIND} * -type d -exec ${MKDIR} "${GWDIR}/{}" \;
.endfor
	cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${GWDIR}/{}" \;
	cd ${WRKSRC}/.programs && ${FIND} * -type f -exec ${INSTALL_PROGRAM} "{}" "${GWDIR}/{}" \;
	cd ${WRKSRC}/.scripts && ${FIND} * -type f -exec ${INSTALL_SCRIPT} "{}" "${GWDIR}/{}" \;

.include <bsd.port.mk>
