# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-aircrafts
PORTVERSION=	20051124
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Aircraft/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft/
DISTFILES=	747_${FGRELDATE}.tgz \
		A320_${FGRELDATE}.tgz \
		a4_${FGRELDATE}.tgz \
		airwaveXtreme150_${FGRELDATE}.tgz \
		AN-225_${FGRELDATE}.tgz \
		as350_${FGRELDATE}.tgz \
		asw20_${FGRELDATE}.tgz \
		b1900d_${FGRELDATE}.tgz \
		b29_${FGRELDATE}.tgz \
		B-52F_${FGRELDATE}.tgz \
		BAC-TSR2_${FGRELDATE}.tgz \
		beech99_${FGRELDATE}.tgz \
		bell206_${FGRELDATE}.tgz \
		Boeing314_1.1.tgz \
		c150_${FGRELDATE}.tgz \
		c172-le_${FGRELDATE}.tgz \
		c172r_${FGRELDATE}.tgz \
		c182_${FGRELDATE}.tgz \
		Canberra_${FGRELDATE}.tgz \
		ch47_${FGRELDATE}.tgz \
		Citation-Bravo_${FGRELDATE}.tgz \
		colditz_${FGRELDATE}.tgz \
		ComperSwift_${FGRELDATE}.tgz \
		Concorde_2.1.tgz \
		dc3_${FGRELDATE}.tgz \
		dhc2_${FGRELDATE}.tgz \
		f104_${FGRELDATE}.tgz \
		f15_${FGRELDATE}.tgz \
		fkdr1_${FGRELDATE}.tgz \
		fokker100_${FGRELDATE}.tgz \
		fokker50_${FGRELDATE}.tgz \
		harrier_${FGRELDATE}.tgz \
		Hurricane_${FGRELDATE}.tgz \
		j22_${FGRELDATE}.tgz \
		Lockheed1049_1.0.tgz \
		marchetti_${FGRELDATE}.tgz \
		MD11_${FGRELDATE}.tgz \
		MiG-15_${FGRELDATE}.tgz \
		ornithopter_${FGRELDATE}.tgz \
		OV10_${FGRELDATE}.tgz \
		paraglider_${FGRELDATE}.tgz \
		pc7_${FGRELDATE}.tgz \
		santa_${FGRELDATE}.tgz \
		seahawk_${FGRELDATE}.tgz \
		sgs233_${FGRELDATE}.tgz \
		shuttle_${FGRELDATE}.tgz \
		sopwithCamel_${FGRELDATE}.tgz \
		Spitfire_${FGRELDATE}.tgz \
		sr20_${FGRELDATE}.tgz \
		T37_${FGRELDATE}.tgz \
		TU-114_${FGRELDATE}.tgz \
		tu154_${FGRELDATE}.tgz \
		X15_${FGRELDATE}.tgz \
		x24b_${FGRELDATE}.tgz \
		YF-23_${FGRELDATE}.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

FGRELDATE=	20051118
PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.plist

post-extract:
	@${RM} -f ${WRKSRC}/b29/LICENSE

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
