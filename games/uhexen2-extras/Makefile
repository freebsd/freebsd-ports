# Created by: alepulver
# $FreeBSD$

PORTNAME=	uhexen2
PORTVERSION=	1.5.6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/HoT%20-%20Other%20content/extra%20data \
		SF/${PORTNAME}/HoT%20-%20Other%20content/hexen2%20mods:mods \
		SF/${PORTNAME}/HoT%20-%20Other%20content/hexenworld%20mods:hw_mods
PKGNAMESUFFIX=	-extras
DISTFILES=	#
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexen II source port extras (demos, mods, etc)

RUN_DEPENDS=	uhexen2>0:games/uhexen2

NO_BUILD=	yes
NO_ARCH=	yes
USES=		tar:tgz

OPTIONS_MULTI=	EXTRA
OPTIONS_MULTI_EXTRA=	HEXEN2_DEMOS HEXEN2_LITS HEXEN2_MODS HW_MODS
OPTIONS_DEFAULT=	HEXEN2_DEMOS HEXEN2_LITS HEXEN2_MODS HW_MODS
OPTIONS_SUB=	yes

HEXEN2_DEMOS_DESC=	Install pre-recorded demos for Hexen II
HEXEN2_DEMOS_DISTFILES=	hexen2-demos${EXTRACT_SUFX}

HEXEN2_LITS_DESC=	Install colored light data for Hexen II
HEXEN2_LITS_DISTFILES=	hexen2-litfiles-20140628.zip

HEXEN2_MODS_DESC=	Install several mods for Hexen II
HEXEN2_MODS_DISTFILES=	apocbot-0.2.0${EXTRACT_SUFX}:mods \
			fo4d${EXTRACT_SUFX}:mods \
			hcbots-1.0.4${EXTRACT_SUFX}:mods

HW_MODS_DESC=		Install several mods for HexenWorld
HW_MODS_DISTFILES=	dungeonbreak${EXTRACT_SUFX}:hw_mods \
			hexarena${EXTRACT_SUFX}:hw_mods \
			hwctf${EXTRACT_SUFX}:hw_mods \
			rivalkingdoms${EXTRACT_SUFX}:hw_mods \
			siege${EXTRACT_SUFX}:hw_mods

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

do-install-HEXEN2_DEMOS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data1
	${INSTALL_DATA} ${WRKDIR}/data1/*demo* ${STAGEDIR}${DATADIR}/data1

do-install-HEXEN2_LITS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data1/maps
	${INSTALL_DATA} ${WRKDIR}/data1/maps/*.lit ${STAGEDIR}${DATADIR}/data1/maps

do-install-HEXEN2_MODS-on:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "apocbot fo4d hcbots" \
		${STAGEDIR}${DATADIR})

do-install-HW_MODS-on:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "db hexarena hwctf rk siege" \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/data1
.for f in hexarena hwctf rk siege
	${INSTALL_DATA} ${WRKDIR}/data1/${f}.cfg ${STAGEDIR}${DATADIR}/data1
.endfor

.include <bsd.port.mk>
