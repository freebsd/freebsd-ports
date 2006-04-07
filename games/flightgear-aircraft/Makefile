# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-aircrafts
PORTVERSION=	20060407
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Aircraft/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft/
DISTFILES=	707_20060324.zip \
		747_${FGRELDATE}.zip \
		A320_${FGRELDATE}.zip \
		a4_${FGRELDATE}.zip \
		Aerostar-700_${FGRELDATE}.zip \
		airwaveXtreme150_${FGRELDATE}.zip \
		AN-225_${FGRELDATE}.zip \
		as350_${FGRELDATE}.zip \
		asw20_${FGRELDATE}.zip \
		b1900d_${FGRELDATE}.zip \
		b29_${FGRELDATE}.zip \
		B-52F_${FGRELDATE}.zip \
		BAC-TSR2_${FGRELDATE}.zip \
		beech99_${FGRELDATE}.zip \
		bell206_${FGRELDATE}.zip \
		Boeing314_1.1.zip \
		c150_${FGRELDATE}.zip \
		c172-le_${FGRELDATE}.zip \
		c172r_${FGRELDATE}.zip \
		c182_${FGRELDATE}.zip \
		CanberraBI8_${FGRELDATE}.zip \
		ch47_${FGRELDATE}.zip \
		Citation_${FGRELDATE}.zip \
		colditz_${FGRELDATE}.zip \
		ComperSwift_${FGRELDATE}.zip \
		Concorde_2.1.zip \
		dc3_${FGRELDATE}.zip \
		dhc2_${FGRELDATE}.zip \
		f104_${FGRELDATE}.zip \
		f15_${FGRELDATE}.zip \
		F80C_20060324.zip \
		fkdr1_${FGRELDATE}.zip \
		fokker100_${FGRELDATE}.zip \
		fokker50_${FGRELDATE}.zip \
		harrier_${FGRELDATE}.zip \
		Hurricane_${FGRELDATE}.zip \
		j22_${FGRELDATE}.zip \
		Lightning_0.1.zip \
		Lockheed1049_1.0.zip \
		Manta_${FGRELDATE}.zip \
		marchetti_${FGRELDATE}.zip \
		MD11_${FGRELDATE}.zip \
		MiG-15_${FGRELDATE}.zip \
		ogel_${FGRELDATE}.zip \
		ornithopter_${FGRELDATE}.zip \
		OV10_${FGRELDATE}.zip \
		OV10_USAFE_${FGRELDATE}.zip \
		pa24-250_${FGRELDATE}.zip \
		paraglider_${FGRELDATE}.zip \
		pc7_${FGRELDATE}.zip \
		santa_${FGRELDATE}.zip \
		seahawk_${FGRELDATE}.zip \
		sgs233_${FGRELDATE}.zip \
		shuttle_${FGRELDATE}.zip \
		sopwithCamel_${FGRELDATE}.zip \
		Spitfire_${FGRELDATE}.zip \
		sr20_${FGRELDATE}.zip \
		T37_${FGRELDATE}.zip \
		TU-114_${FGRELDATE}.zip \
		tu154_${FGRELDATE}.zip \
		X15_${FGRELDATE}.zip \
		x24b_${FGRELDATE}.zip \
		YF-23_${FGRELDATE}.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

FGRELDATE=	20060323
PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.plist

post-patch:
	@${RM} -f ${WRKSRC}/b29/LICENSE
.for d in AN-225 B-52F BAC-TSR2 Boeing314/Models CanberraBI8 \
	Lockheed1049/Models MiG-15 TU-114 YF-23
	@${RM} -f ${WRKSRC}/${d}/COPYING
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type d ! -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm share/FlightGear/Aircraft/|' >> ${PLIST}

do-install:
	cd ${WRKSRC} && \
	${FIND} * -type d ! -empty -exec \
		${MKDIR} "${PREFIX}/share/FlightGear/Aircraft/{}" \; && \
	${FIND} * -type f -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/share/FlightGear/Aircraft/{}" \;

.include <bsd.port.mk>
