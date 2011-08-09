# New ports collection makefile for:	uhexen2-extras
# Date created:				2006-12-30
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	uhexen2
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/HoT%20-%20Other%20content/extra%20data
PKGNAMESUFFIX=	-extras
EXTRACT_SUFX=	.tgz
DISTFILES=	#
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexen II source port extras (demos, mods, etc)

RUN_DEPENDS=	${DATADIR}:${PORTSDIR}/games/uhexen2

NO_BUILD=	yes

OPTIONS=	HEXEN2_DEMOS "Install pre-recorded demos for Hexen II" on \
		HEXEN2_LITS "Install colored light data for Hexen II" on \
		HEXEN2_MODS "Install several mods for Hexen II" on \
		HW_MODS "Install several mods for HexenWorld" on

.include <bsd.port.pre.mk>

.if defined(WITH_HEXEN2_DEMOS)
DISTFILES+=	hexen2-demos${EXTRACT_SUFX}
PLIST_SUB+=	HEXEN2_DEMOS=""
.else
PLIST_SUB+=	HEXEN2_DEMOS="@comment "
.endif

.if defined(WITH_HEXEN2_LITS)
DISTFILES+=	hexen2-lit_files${EXTRACT_SUFX}
PLIST_SUB+=	HEXEN2_LITS=""
.else
PLIST_SUB+=	HEXEN2_LITS="@comment "
.endif

.if defined(WITH_HEXEN2_MODS)
MASTER_SITES+=	SF/${PORTNAME}/HoT%20-%20Other%20content/hexen2%20mods:mods
DISTFILES+=	apocbot-0.2.0${EXTRACT_SUFX}:mods \
		fo4d${EXTRACT_SUFX}:mods \
		hcbots-1.0.4${EXTRACT_SUFX}:mods
PLIST_SUB+=	HEXEN2_MODS=""
.else
PLIST_SUB+=	HEXEN2_MODS="@comment "
.endif

.if defined(WITH_HW_MODS)
MASTER_SITES+=	SF/${PORTNAME}/HoT%20-%20Other%20content/hexenworld%20mods:hw_mods
DISTFILES+=	dungeonbreak${EXTRACT_SUFX}:hw_mods \
		hexarena${EXTRACT_SUFX}:hw_mods \
		hwctf${EXTRACT_SUFX}:hw_mods \
		rivalkingdoms${EXTRACT_SUFX}:hw_mods \
		siege${EXTRACT_SUFX}:hw_mods
PLIST_SUB+=	HW_MODS=""
.else
PLIST_SUB+=	HW_MODS="@comment "
.endif

.if empty(DISTFILES)
IGNORE=		needs at least one option selected
.endif

do-install:
.if defined(WITH_HEXEN2_DEMOS)
	${INSTALL_DATA} ${WRKDIR}/data1/*demo* ${DATADIR}/data1
.endif
.if defined(WITH_HEXEN2_LITS)
	${MKDIR} ${DATADIR}/data1/maps
	${INSTALL_DATA} ${WRKDIR}/data1/maps/*.lit ${DATADIR}/data1/maps
.endif
.if defined(WITH_HEXEN2_MODS)
.for f in apocbot fo4d hcbots
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} ${f} ${DATADIR})
.endfor
.endif
.if defined(WITH_HW_MODS)
.for f in db hexarena hwctf rk siege
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} ${f} ${DATADIR})
.endfor
.for f in hexarena hwctf rk siege
	${INSTALL_DATA} ${WRKDIR}/data1/${f}.cfg ${DATADIR}/data1
.endfor
.endif

.include <bsd.port.post.mk>
