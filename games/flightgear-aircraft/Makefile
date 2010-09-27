# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FlightGear-aircrafts
PORTVERSION=	20081221
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft/ \
		ftp://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Aircraft/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Aircraft/ \
		http://ftp3.linux.kiev.ua/pub/fgfs/Aircraft/ \
		ftp://ftp.ibiblio.org/pub/mirrors/flightgear/ftp/Aircraft/ \
		ftp://ftp.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.is.co.za/pub/games/flightgear/ftp/Aircraft/
# exclude planes already included in flightgear-data
DISTFILES=	14bis_20080922.zip \
		707_20080509.zip \
		737-300_20071215.zip \
		747-200_1.1.zip \
		747_20071215.zip \
		787_02_2008.zip \
		A-10_20081023.zip \
		A-6E_20081124.zip \
		A24-Viking_20080427.zip \
		A300_20061009.zip \
		A320-family_20070115.zip \
		A320_20070115.zip \
		A380_1.0.zip \
		AN-225_20071114.zip \
		ANT-20_20080813.zip \
		AR-234_20080805.zip \
		ASK21_20070701.zip \
		Aerostar-700_20080805.zip \
		Albatross_20080304.zip \
		Alouette-III_20080304.zip \
		Alouette-II_20081215.zip \
		Alphajet_20081130.zip \
		Arsenal-VG33_20080808.zip \
		B-17_20081126.zip \
		B-1B_20081214.zip \
		B-2_20080304.zip \
		B-52F_20071130.zip \
		B737_20050614.zip \
		BAC-TSR2_20080103.zip \
		BV-141_20081118.zip \
		Bernard-HV220_20080808.zip \
		Boeing314_1.3.zip \
		Buccaneer_0.1.zip \
		Bugatti_20080922.zip \
		C-2A_20081220.zip \
		C130_20081122.zip \
		C684_20081116.zip \
		CanberraBI8_20071106.zip \
		Caravelle_20081114.zip \
		Carreidas_20080808.zip \
		Citation-Bravo_20081214.zip \
		Citation_20080503.zip \
		ComperSwift_20071106.zip \
		Concorde_2.5.zip \
		DH-88_20080805.zip \
		DH-89_20080304.zip \
		DH-91_20080805.zip \
		DO-335_20080828.zip \
		DO-X_20081030.zip \
		DR400_20081214.zip \
		Dauphin_20081119.zip \
		Deuche_20081220.zip \
		E3B_20080304.zip \
		F-86_20080304.zip \
		F-8E-Crusader_20081219.zip \
		F4U_20081214.zip \
		F80C_20070521.zip \
		FK9MK2_20080828.zip \
		Farman-IV_20080304.zip \
		Gee-Bee_20080808.zip \
		Grob-G109_20080828.zip \
		Grob-G115_20080922.zip \
		H-21C-Shawnee_20080304.zip \
		H1-Racer_20080808.zip \
		H4-Hercules_0.9.zip \
		HUP-Retriever_20080304.zip \
		Hansajet_0.1.zip \
		He162_20080223.zip \
		HondaJet_20080810.zip \
		Hornet_20081221.zip \
		Hughes-XF11_20080808.zip \
		Hunter_20070905.zip \
		Hurricane_20081219.zip \
		KC135_20080828.zip \
		Ki-84_20081219.zip \
		Lightning_20081023.zip \
		Lionceau_20081023.zip \
		Lockheed-SR71_20081023.zip \
		Lockheed1049_1.2.zip \
		Long-EZ_20080828.zip \
		Lynx-WG13_20080304.zip \
		MD11_20070618.zip \
		ME-262_20080808.zip \
		Macchi-Castoldi-MC72_20080910.zip \
		Malolo1_0.0.zip \
		MiG-15_20071106.zip \
		Mig-29_20081023.zip \
		NTPS_20081023.zip \
		Noratlas_20081219.zip \
		OH-1_0.1.zip \
		OV10_20070506.zip \
		P-38-Lightning_20081201.zip \
		P180_20080212.zip \
		PBY-Catalina_20081201.zip \
		PC-6_20080922.zip \
		Quickie_20081214.zip \
		R22_20080503.zip \
		Rascal_0.1.zip \
		Ryan-SoSL_20081116.zip \
		S-51-Dragonfly_20081116.zip \
		SM-55_20080916.zip \
		SR71-BlackBird_20081219.zip \
		SU-37_20080202.zip \
		SaabJ35Draken_20080304.zip \
		SeaVixen_20080304.zip \
		Sikorsky-76C_20081116.zip \
		Sikorsky-S58_20080523.zip \
		Skyranger_20080816.zip \
		Spitfire_20070619.zip \
		Stampe-SV4_20081116.zip \
		Starship_20081023.zip \
		Stieglitz_20080310.zip \
		Stiletto_20080304.zip \
		Storch_20081023.zip \
		Su-26M_1.0.zip \
		Submarine_Scout_0.1.zip \
		Super-Frelon_20080304.zip \
		Supermarine-S.6B_20080310.zip \
		Superwal_20080221.zip \
		T-4_20080719.zip \
		T37_20081023.zip \
		T38_20081023.zip \
		TBM-Avenger_20081116.zip \
		TU-114_20080103.zip \
		UH-60_20080810.zip \
		V22-Osprey_0.1.zip \
		Velocity-XL_20081021.zip \
		Vickers-Vimy_20080922.zip \
		X15_20061204.zip \
		YF-23_20081030.zip \
		YardStik_0.0.zip \
		ZF_Navy_free_balloon_0.1.zip \
		ZivkoEdge_0.1.zip \
		Zlin-50lx_20081030.zip \
		a4_20080828.zip \
		airwaveXtreme150_20050430.zip \
		an2_20080828.zip \
		apache_20080617.zip \
		asw20_20050430.zip \
		b29_20081030.zip \
		beaufighter_20081207.zip \
		beech99_20080304.zip \
		bf109_20081023.zip \
		bleriot-XI_20080304.zip \
		bluebird_8.7.zip \
		bocian_20080722.zip \
		c150_20080304.zip \
		c172r_20060313.zip \
		c182_20080808.zip \
		c182rg_20080707.zip \
		c310_20080808.zip \
		c310u3a_20070206.zip \
		ch47_0.1.zip \
		ch53e_0.1.zip \
		colditz_20070515.zip \
		couzinet70_20080811.zip \
		cri-cri_20080304.zip \
		dc3_20050614.zip \
		dc6_20081009.zip \
		dhc3_20080805.zip \
		dhc6_20080503.zip \
		ec135_0.4.zip \
		ercoupe_20081117.zip \
		eurofighter_20080707.zip \
		f104_20080808.zip \
		f15c_20081106.zip \
		f16_20081023.zip \
		f18_20070317.zip \
		fkdr1_20080805.zip \
		flash2a_20080304.zip \
		fokker100_20081023.zip \
		fokker50_20081116.zip \
		fw190_20081204.zip \
		harrier_20070615.zip \
		j22_20050614.zip \
		j7w_20081219.zip \
		jeep_20081023.zip \
		ju52_20080304.zip \
		marchetti_20050614.zip \
		mirage2000_20070103.zip \
		mosquito_20080304.zip \
		ogel_20080503.zip \
		ornithopter_20050430.zip \
		p51d_20081030.zip \
		pa24-250_20081215.zip \
		pa28-161_20080322.zip \
		paraglider_20060114.zip \
		payen-pa100_20080813.zip \
		pc7_20081023.zip \
		pittss1c_20080707.zip \
		pushback_20080405.zip \
		santa_20051026.zip \
		seahawk_20081129.zip \
		sgs233_20070506.zip \
		shuttle_20080808.zip \
		snowplow_1.0.zip \
		spitfireIX_20080304.zip \
		sr20_20051010.zip \
		truck_20071027.zip \
		tu154_20060501.zip \
		vulcanb2_20080304.zip \
		wrightFlyer1903_20050430.zip \
		x24b_20060114.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/flightgear-data

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
		| ${SED} -e 's|^|@exec ${MKDIR} share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm share/FlightGear/Aircraft/|' >> ${PLIST}

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/FlightGear/Aircraft/)

.include <bsd.port.mk>
