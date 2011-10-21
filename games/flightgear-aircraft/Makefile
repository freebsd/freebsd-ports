# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-aircrafts
PORTVERSION=	20111013
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Aircraft-2.4/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Aircraft-2.4/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft-2.4/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft-2.4/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Aircraft-2.4/
# Selection of production-ready/well-known planes
# (planes already included in flightgear-data are excluded)
# Please contact the MAINTAINER if a plane is missing
DISTFILES=	737-200_20110713.zip \
		A-10_20110629.zip \
		A300_20101217.zip \
		Alouette-II_20110523.zip \
		Alphajet_20110228.zip \
		B-17_20110516.zip \
		Breguet-XIX_20101217.zip \
		C130_20101217.zip \
		Caravelle_20101217.zip \
		Caudron-G3_20101217.zip \
		F80C_20101217.zip \
		Hurricane_20110815.zip \
		IL-2_20110324.zip \
		Lightning_20110705.zip \
		Lockheed1049h_1.0.zip \
		Messerschmitt-P1101_20101217.zip \
		MirageIII_20110124.zip \
		PaperAirplane_20110103.zip \
		Pond-Racer_20101217.zip \
		R44_20110523.zip \
		Spitfire_20110705.zip \
		Stieglitz_20101217.zip \
		Super-Etendard_20110324.zip \
		Supermarine-S.6B_20110118.zip \
		Superwal_20101217.zip \
		airwaveXtreme150_20101217.zip \
		asw20_20101217.zip \
		bf109_20110629.zip \
		c310_20110113.zip \
		dhc3_20110411.zip \
		f16_20110629.zip \
		harrier_20101217.zip \
		pa24-250_20110222.zip \
		tu154_20101217.zip \
		wrightFlyer1903_20101217.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Selection of additional aircraft for the FlightGear flight simulator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=	${WRKDIR}/.pkg-plist

MANUAL_PACKAGE_BUILD=	package exceeds pointyhat filesize limit

post-patch:
	@${FIND} ${WRKSRC} -type f \
		\( -name COPYING -or -name LICENSE -or -name copyright \) -delete

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} share/flightgear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|share/flightgear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm share/flightgear/Aircraft/|' >> ${PLIST}

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/flightgear/Aircraft/)

.include <bsd.port.mk>
