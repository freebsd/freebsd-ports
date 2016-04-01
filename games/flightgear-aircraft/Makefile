# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flightgear-aircraft
PORTVERSION=	20160305
CATEGORIES=	games
# See http://www.flightgear.org/templates.js
MASTER_SITES=	http://fgfs.goneabitbursar.com/official/ \
	http://mirrors.ibiblio.org/flightgear/ftp/Aircraft-2016.1/ \
	http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Aircraft-2016.1/
# Selection of production-ready/well-known planes
# (planes already included in flightgear-data are excluded)
# Please contact MAINTAINER if a plane is missing
DISTFILES=	737-200.zip \
	A-10.zip \
	A300.zip \
	Alouette-II.zip \
	Alphajet.zip \
	B-17.zip \
	Breguet-XIX.zip \
	C130.zip \
	Caravelle.zip \
	Caudron-G3.zip \
	F80C.zip \
	Hurricane.zip \
	IL-2.zip \
	Lightning.zip \
	Lockheed1049h.zip \
	Messerschmitt-P1101.zip \
	MirageIII.zip \
	PaperAirplane.zip \
	Pond-Racer.zip \
	R44.zip \
	Spitfire.zip \
	Stieglitz.zip \
	Super-Etendard.zip \
	Supermarine-S.6B.zip \
	Superwal.zip \
	airwaveXtreme150.zip \
	asw20.zip \
	bf109.zip \
	c310.zip \
	dhc3.zip \
	f16.zip \
	harrier.zip \
	pa24-250.zip \
	tu154.zip \
	wrightFlyer1903.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Selection of additional aircraft for the FlightGear flight simulator

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/flightgear/version:games/flightgear-data

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
