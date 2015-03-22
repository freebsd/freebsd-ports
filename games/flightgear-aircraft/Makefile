# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flightgear-aircraft
PORTVERSION=	20150303
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/flightgear/ftp/Aircraft-3.4/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Aircraft-3.4/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft-3.4/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft-3.4/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Aircraft-3.4/
# Selection of production-ready/well-known planes
# (planes already included in flightgear-data are excluded)
# Please contact the MAINTAINER if a plane is missing
DISTFILES=	737-200_20140909.zip \
		A-10_20140909.zip \
		A300_20140909.zip \
		Alouette-II_20140909.zip \
		Alphajet_20140909.zip \
		B-17_0.1.zip \
		Breguet-XIX_20140909.zip \
		C130_20140909.zip \
		Caravelle_20140909.zip \
		Caudron-G3_20140909.zip \
		F80C_20140909.zip \
		Hurricane_20140909.zip \
		IL-2_20140909.zip \
		Lightning_20140909.zip \
		Lockheed1049h_1.0.zip \
		Messerschmitt-P1101_20140909.zip \
		MirageIII_20140909.zip \
		PaperAirplane_20140909.zip \
		Pond-Racer_20140909.zip \
		R44_20140909.zip \
		Spitfire_20140909.zip \
		Stieglitz_20140909.zip \
		Super-Etendard_20140909.zip \
		Supermarine-S.6B_20140909.zip \
		Superwal_20140909.zip \
		airwaveXtreme150_January-2015.zip \
		asw20_June-2014.zip \
		bf109_20140909.zip \
		c310_20150114.zip \
		dhc3_0.1.zip \
		f16_20140909.zip \
		harrier_20140909.zip \
		pa24-250_20140909.zip \
		tu154_20140909.zip \
		wrightFlyer1903_20140909.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Selection of additional aircraft for the FlightGear flight simulator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

NO_BUILD=	yes
USES=		zip
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
	${FIND} * -type d -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dir %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
