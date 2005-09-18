# New ports collection makefile for:	flightgear-aircrafts
# Date created:				19 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-aircrafts
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Aircraft/
DISTFILES=	747_20050118.tgz \
		A320_20050118.tgz \
		a4_20050118.tgz \
		airwaveXtreme150_20050118.tgz \
		AN-225_20050222.tgz \
		as350_20050118.tgz \
		asw20_20050118.tgz \
		b1900d_20050124.tgz \
		B-52F_20050125.tgz \
		BAC-TSR2_20050120.tgz \
		beech99_20050118.tgz \
		bell206_20050118.tgz \
		Boeing314_20050125.tgz \
		c172-le_20050118.tgz \
		c172r_20050118.tgz \
		c182_20050118.tgz \
		Canberra_20050118.tgz \
		ch47_20050118.tgz \
		Citation_20050118.tgz \
		ComperSwift_20050118.tgz \
		Concorde_2.0.tgz \
		dc3_20050118.tgz \
		f104_20050118.tgz \
		f15_20050118.tgz \
		fkdr1_20050118.tgz \
		fokker100_20050326.tgz \
		fokker50_20050118.tgz \
		harrier_20050118.tgz \
		j22_20050118.tgz \
		marchetti_20050118.tgz \
		MD11_20050118.tgz \
		ornithopter_20050118.tgz \
		OV10_20050118.tgz \
		paraglider_20050118.tgz \
		pc7_20050118.tgz \
		seahawk_20050118.tgz \
		sgs233_20050118.tgz \
		shuttle_20050118.tgz \
		sopwithCamel_20050118.tgz \
		Spitfire_20050118.tgz \
		T37_20050118.tgz \
		T38_20050118.tgz \
		tu154_20050118.tgz \
		X15_20050118.tgz \
		x24b_20050118.tgz \
		YF-23_20050118.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Additional aircrafts for the FlightGear flight simulator

RUN_DEPENDS=	${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/.plist

post-extract:
	@${FIND} ${WRKSRC} \( -name '.#*' -or -name '*~' -or -name COPYING \) \
		-delete

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
