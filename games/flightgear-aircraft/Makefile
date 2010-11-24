# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FlightGear-aircrafts
PORTVERSION=	20100302
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Aircraft-2.0.0/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Aircraft-2.0.0/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft-2.0.0/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft-2.0.0/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Aircraft-2.0.0/
# exclude planes already included in flightgear-data
DISTFILES=	14bis_20080922.zip \
		21_20090313.zip \
		707_20080509.zip \
		727-230_20100301.zip \
		737-100_20100216.zip \
		737-300_20100302.zip \
		747-200_1.1.zip \
		747-400_20100228.zip \
		747_20071215.zip \
		767-300_20100100.zip \
		787_200802.zip \
		A-10_20100227.zip \
		A-26-Invader_20090912.zip \
		A-6E_20091019.zip \
		A24-Viking_20090620.zip \
		A300_20061009.zip \
		A320-family_20070115.zip \
		A320_20070115.zip \
		A340-600_20080400.zip \
		A380_1.0.zip \
		AN-225_20071114.zip \
		ANT-20_20100216.zip \
		AR-234_20100213.zip \
		ASK21-MI_20090202.zip \
		ASK21_20070701.zip \
		ATC_20100302.zip \
		Aerostar-700_20090930.zip \
		AirCrane_20091207.zip \
		Albatross_20080304.zip \
		Allegro-2000_20100216.zip \
		Alouette-III_20080304.zip \
		Alouette-II_20090620.zip \
		Alphajet_20091229.zip \
		Arsenal-VG33_20091229.zip \
		Arup-S2_20090718.zip \
		Avro-Lancaster_20090907.zip \
		B-17_20091229.zip \
		B-1B_20100123.zip \
		B-24-Liberator_20090907.zip \
		B-25_20091112.zip \
		B-2_20080304.zip \
		B-52F_20071130.zip \
		B737_20050614.zip \
		BAC-TSR2_20080103.zip \
		BV-141_20090418.zip \
		Bernard-HV220_20090522.zip \
		Boeing314_1.3.zip \
		Bombardier-415_20090310.zip \
		Buccaneer_0.1.zip \
		Bugatti_20090419.zip \
		C-2A_20081220.zip \
		C130_20100302.zip \
		C684_20100124.zip \
		CanberraBI8_20071106.zip \
		Caravelle_20091229.zip \
		Carreidas_20100227.zip \
		Citation-Bravo_20100216.zip \
		Citation_20100201.zip \
		ComperSwift_20071106.zip \
		Concorde_2.6.zip \
		Convair-XFY-1-Pogo_20090301.zip \
		DH-88_20090302.zip \
		DH-89_20090303.zip \
		DH-91_20080805.zip \
		DO-335_20090303.zip \
		DO-X_20090702.zip \
		DR400_20100216.zip \
		Dauphin_20090620.zip \
		Deperdussin_20090126.zip \
		DerKleineUhu_0.1.zip \
		Deuche_20081220.zip \
		E3B_20090301.zip \
		F-106-dart_20090110.zip \
		F-117_20100302.zip \
		F-86_20090529.zip \
		F-8E-Crusader_20090405.zip \
		F4U_20100216.zip \
		F6F-Hellcat_20100110.zip \
		F80C_20070521.zip \
		FK9MK2_20090522.zip \
		Farman-IV_20090522.zip \
		Fokker-S-11_20091216.zip \
		Fouga-Magister_20100216.zip \
		Fw61_20091025.zip \
		Gee-Bee_20090715.zip \
		Grob-G109_20080828.zip \
		Grob-G115_20090715.zip \
		H-21C-Shawnee_20080304.zip \
		H1-Racer_20100201.zip \
		H4-Hercules_20091229.zip \
		HM-14_20100101.zip \
		HUP-Retriever_20080304.zip \
		Hansajet_0.1.zip \
		He162_20080223.zip \
		HondaJet_20091229.zip \
		Hornet_20090406.zip \
		Horten-Ho-IX_20091229.zip \
		Hughes-XF11_20080808.zip \
		Hunter_20090202.zip \
		Hurricane_20100227.zip \
		IL-2_20090604.zip \
		Jaguar_20090529.zip \
		Ju-87_20100227.zip \
		Junkers-G.38ce_20090704.zip \
		K5Y1_0.1.zip \
		KC135_20090327.zip \
		Ka-50_20090620.zip \
		Katana_20091010.zip \
		Ki-84_20081219.zip \
		L-1011-500_20090418.zip \
		La-5_20090603.zip \
		Lancair-235_20090307.zip \
		Lightning_20081023.zip \
		Lionceau_20091229.zip \
		Lockheed-NF104A_20100216.zip \
		Lockheed-SR71_20081023.zip \
		Lockheed-Vega_20100216.zip \
		Lockheed1049_1.3.zip \
		Long-EZ_20091022.zip \
		Lynx-WG13_20080304.zip \
		MB326_20090709.zip \
		MD11_20070618.zip \
		ME-262HGIII_20091229.zip \
		ME-262_20091130.zip \
		MPCarrier_0.1.zip \
		MRJ_20090820.zip \
		Macchi-Castoldi-MC72_20090522.zip \
		Malolo1_0.0.zip \
		MiG-15_20071106.zip \
		Mig-29_20100302.zip \
		Noratlas_20081219.zip \
		Northrop-xb35_20100123.zip \
		OH-1_0.1.zip \
		OV10_20100123.zip \
		P-38-Lightning_20090115.zip \
		P180_20080212.zip \
		P47_20090316.zip \
		PBY-Catalina_20090411.zip \
		PC-6_20090930.zip \
		Polikarpov-I16_20090529.zip \
		Pond-Racer_20091229.zip \
		Quickie_20091229.zip \
		R22_20080503.zip \
		RV-6A_0.1.zip \
		RafaleB_20100205.zip \
		Rascal_0.1.zip \
		Ryan-PT22_20091229.zip \
		Ryan-SoSL_20090622.zip \
		S-51-Dragonfly_20081116.zip \
		SM-55_20091229.zip \
		SPAD-VII_20090725.zip \
		SR71-BlackBird_20090930.zip \
		SU-37_20080202.zip \
		SaabJ35Draken_20080304.zip \
		SeaVixen_20080304.zip \
		Sikorsky-76C_20090406.zip \
		Sikorsky-S38_20090802.zip \
		Sikorsky-S58_20090331.zip \
		Skyranger_20090522.zip \
		Skyvan_20090416.zip \
		Spitfire_20100227.zip \
		Stampe-SV4_20091229.zip \
		Starship_20090620.zip \
		Stearman_20090921.zip \
		Stieglitz_20091028.zip \
		Stiletto_20091229.zip \
		Storch_1.0.zip \
		Su-26M_1.0.zip \
		Submarine_Scout_1.0.zip \
		Super-Frelon_20090620.zip \
		Supermarine-S.6B_20090427.zip \
		Superwal_20091028.zip \
		T-4_20080719.zip \
		T37_20081023.zip \
		T38_20081023.zip \
		TBM-Avenger_20081116.zip \
		TU-114_20080103.zip \
		Tigre_20090702.zip \
		UH-1_20091207.zip \
		UH-60_20090331.zip \
		V22-Osprey_0.2.zip \
		Velocity-XL_20090603.zip \
		Vickers-Vimy_20080922.zip \
		X15_20061204.zip \
		YF-23_20081030.zip \
		YS-11_0.1.zip \
		YardStik_0.0.zip \
		ZF_Navy_free_balloon_1.0.zip \
		ZivkoEdge_0.1.zip \
		Zlin-50lx_20091229.zip \
		a4_20080828.zip \
		airwaveXtreme150_20050430.zip \
		an2_20080828.zip \
		apache_20080617.zip \
		as332_20091229.zip \
		asw20_20050430.zip \
		b26_20100130.zip \
		b29_20081030.zip \
		beaufighter_20100216.zip \
		beech99_20080304.zip \
		bf109_20100201.zip \
		bleriot-XI_20090323.zip \
		bluebird_10.4.zip \
		bocian_20080722.zip \
		c150_20091117.zip \
		c172r_20060313.zip \
		c182_20080808.zip \
		c182rg_20080707.zip \
		c310_20090129.zip \
		c310u3a_20070206.zip \
		ch47_0.1.zip \
		ch53e_0.1.zip \
		colditz_20070515.zip \
		couzinet70_20100123.zip \
		cri-cri_20080304.zip \
		dc2_20100302.zip \
		dc3_20091117.zip \
		dc6_20091112.zip \
		dhc3_20091229.zip \
		dhc6_20090901.zip \
		dhc8_20090218.zip \
		ec130_0.1.zip \
		ec135_0.6.zip \
		ercoupe_20081117.zip \
		eurofighter_20100302.zip \
		f15c_20081106.zip \
		f16_20100123.zip \
		f18_20070317.zip \
		fkdr1_20090820.zip \
		flash2a_20080304.zip \
		fokker100_20091117.zip \
		fokker50_20090529.zip \
		fw190_20100227.zip \
		harrier_20100123.zip \
		j22_20050614.zip \
		j7w_20081219.zip \
		jeep_20100201.zip \
		ju52_20100216.zip \
		l39_20100219.zip \
		marchetti_20050614.zip \
		mirage2000_20070103.zip \
		mosquito_20090808.zip \
		ogel_20090323.zip \
		ornithopter_20050430.zip \
		p51d_20100227.zip \
		pa22_20090702.zip \
		pa24-250_20100123.zip \
		pa28-161_20091229.zip \
		paraglider_20060114.zip \
		payen-pa100_20090405.zip \
		pc7_20090418.zip \
		pittss1c_20100216.zip \
		pushback_20080405.zip \
		rallye-MS893_20090404.zip \
		santa_20051026.zip \
		seahawk_20100204.zip \
		sgs233_20070506.zip \
		shuttle_20080808.zip \
		snowplow_1.0.zip \
		spitfireIX_20100216.zip \
		sr20_20051010.zip \
		truck_20071027.zip \
		tu154_20060501.zip \
		victor_20100302.zip \
		vulcanb2_20091103.zip \
		wrightFlyer1903_20050430.zip \
		x24b_20060114.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/flightgear-data

LICENSE=	GPLv2

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
