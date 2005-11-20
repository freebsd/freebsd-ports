# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-aircrafts
PORTVERSION=	20051118
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft/
DISTFILES=	747_${PORTVERSION}.tgz \
		A320_${PORTVERSION}.tgz \
		A380_${PORTVERSION}.tgz \
		a4_${PORTVERSION}.tgz \
		airwaveXtreme150_${PORTVERSION}.tgz \
		AN-225_${PORTVERSION}.tgz \
		as350_${PORTVERSION}.tgz \
		asw20_${PORTVERSION}.tgz \
		b1900d_${PORTVERSION}.tgz \
		b29_${PORTVERSION}.tgz \
		B-52F_${PORTVERSION}.tgz \
		BAC-TSR2_${PORTVERSION}.tgz \
		beech99_${PORTVERSION}.tgz \
		bell206_${PORTVERSION}.tgz \
		Boeing314_${PORTVERSION}.tgz \
		c150_${PORTVERSION}.tgz \
		c172-le_${PORTVERSION}.tgz \
		c172r_${PORTVERSION}.tgz \
		c182_${PORTVERSION}.tgz \
		Canberra_${PORTVERSION}.tgz \
		ch47_${PORTVERSION}.tgz \
		Citation-Bravo_${PORTVERSION}.tgz \
		colditz_${PORTVERSION}.tgz \
		ComperSwift_${PORTVERSION}.tgz \
		Concorde_2.0.tgz \
		dc3_${PORTVERSION}.tgz \
		dhc2_${PORTVERSION}.tgz \
		f104_${PORTVERSION}.tgz \
		f15_${PORTVERSION}.tgz \
		fkdr1_${PORTVERSION}.tgz \
		fokker100_${PORTVERSION}.tgz \
		fokker50_${PORTVERSION}.tgz \
		harrier_${PORTVERSION}.tgz \
		Hurricane_${PORTVERSION}.tgz \
		j22_${PORTVERSION}.tgz \
		l410_${PORTVERSION}.tgz \
		marchetti_${PORTVERSION}.tgz \
		MD11_${PORTVERSION}.tgz \
		MiG-15_${PORTVERSION}.tgz \
		ornithopter_${PORTVERSION}.tgz \
		OV10_${PORTVERSION}.tgz \
		paraglider_${PORTVERSION}.tgz \
		pc7_${PORTVERSION}.tgz \
		santa_${PORTVERSION}.tgz \
		seahawk_${PORTVERSION}.tgz \
		sgs233_${PORTVERSION}.tgz \
		shuttle_${PORTVERSION}.tgz \
		sopwithCamel_${PORTVERSION}.tgz \
		Spitfire_${PORTVERSION}.tgz \
		sr20_${PORTVERSION}.tgz \
		T37_${PORTVERSION}.tgz \
		TU-114_${PORTVERSION}.tgz \
		tu154_${PORTVERSION}.tgz \
		X15_${PORTVERSION}.tgz \
		x24b_${PORTVERSION}.tgz \
		YF-23_${PORTVERSION}.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

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
