# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flightgear-aircraft
PORTVERSION=	20131001
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/flightgear/ftp/Aircraft-2.12/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Aircraft-2.12/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft-2.12/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft-2.12/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Aircraft-2.12/
# Selection of production-ready/well-known planes
# (planes already included in flightgear-data are excluded)
# Please contact the MAINTAINER if a plane is missing
DISTFILES=	737-200_20120506.zip \
		A-10_20121203.zip \
		A300_20120717.zip \
		Alouette-II_20120506.zip \
		Alphajet_20130225.zip \
		B-17_20130706.zip \
		Breguet-XIX_20100829.zip \
		C130_20130810.zip \
		Caravelle_20120506.zip \
		Caudron-G3_20120506.zip \
		F80C_20120717.zip \
		Hurricane_20130315.zip \
		IL-2_20110311.zip \
		Lightning_20121005.zip \
		Lockheed1049h_1.0.zip \
		Messerschmitt-P1101_20130315.zip \
		MirageIII_20120222.zip \
		PaperAirplane_20101229.zip \
		Pond-Racer_20120506.zip \
		R44_20130426.zip \
		Spitfire_20130310.zip \
		Stieglitz_20091025.zip \
		Super-Etendard_20120501.zip \
		Supermarine-S.6B_20130312.zip \
		Superwal_20100330.zip \
		airwaveXtreme150_July-2013.zip \
		asw20_July-2013.zip \
		bf109_20130615.zip \
		c310_20130209.zip \
		dhc3_20120506.zip \
		f16_20120812.zip \
		harrier_20120717.zip \
		pa24-250_20121128.zip \
		tu154_20081221.zip \
		wrightFlyer1903_20070710.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Selection of additional aircraft for the FlightGear flight simulator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

NO_BUILD=	yes
USES=		zip:infozip
WRKSRC=	${WRKDIR}/fgaircraft
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
DATADIR=	${PREFIX}/share/flightgear/Aircraft

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

pre-extract:
	@${MKDIR} ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -type f \
		\( -name COPYING -or -name LICENSE -or -name copyright \) -delete

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} %D/share/flightgear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
