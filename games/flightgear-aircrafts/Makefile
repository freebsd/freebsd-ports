# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-aircrafts
PORTVERSION=	20060413
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Aircraft/ \
		ftp://ftp.sunsite.org.uk/sites/ftp.flightgear.org/flightgear-ftp/Aircraft/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Aircraft/
DISTFILES=	707_20060324.zip \
		747_20060315.zip \
		A320_20060405.zip \
		a4_20060320.zip \
		Aerostar-700_20060216.zip \
		airwaveXtreme150_20050502.zip \
		AN-225_20060226.zip \
		as350_20050502.zip \
		asw20_20050502.zip \
		b1900d_20060410.zip \
		b29_20060324.zip \
		B-52F_20060220.zip \
		BAC-TSR2_20060220.zip \
		beech99_20050502.zip \
		bell206_20050502.zip \
		Boeing314_1.2.zip \
		c150_20051116.zip \
		c172-le_20031220.zip \
		c172r_20060315.zip \
		c182_20060315.zip \
		CanberraBI8_20060323.zip \
		ch47_20051128.zip \
		Citation_20051216.zip \
		colditz_20051108.zip \
		ComperSwift_20060220.zip \
		Concorde_2.2.zip \
		dc3_20050616.zip \
		dhc2_20060315.zip \
		f104_20060315.zip \
		f15_20060112.zip \
		F80C_20060324.zip \
		fkdr1_20050502.zip \
		fokker100_20060315.zip \
		fokker50_20060228.zip \
		harrier_20050616.zip \
		Hurricane_20060131.zip \
		j22_20050616.zip \
		Lightning_20060324.zip \
		Lockheed1049_1.1.zip \
		Manta_20060206.zip \
		marchetti_20050616.zip \
		MD11_20060315.zip \
		MiG-15_20060220.zip \
		ogel_20060117.zip \
		ornithopter_20050502.zip \
		OV10_20060216.zip \
		OV10_USAFE_20060216.zip \
		pa24-250_20060324.zip \
		paraglider_20060112.zip \
		pc7_20060315.zip \
		santa_20051027.zip \
		seahawk_20060320.zip \
		sgs233_20060112.zip \
		shuttle_20060112.zip \
		sopwithCamel_20050502.zip \
		Spitfire_20051216.zip \
		sr20_20051009.zip \
		T37_20060315.zip \
		TU-114_20051027.zip \
		tu154_20050502.zip \
		X15_20060112.zip \
		x24b_20060112.zip \
		YF-23_20060226.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

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
