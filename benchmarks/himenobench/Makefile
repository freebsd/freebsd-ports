# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	himenobench
PORTVERSION=	2004.08.16
PORTREVISION=	5
CATEGORIES=	benchmarks
MASTER_SITES=	http://accc.riken.jp/secure/4502/:C http://accc.riken.jp/secure/4503/:C \
		http://accc.riken.jp/secure/4504/:F90 http://accc.riken.jp/secure/4505/:F77
DISTFILES=	himenoBMTxp_xl.lzh:F77 himenoBMTxp_l.lzh:F77 himenoBMTxp_m.lzh:F77 \
		himenoBMTxp_s.lzh:F77 cc_himenoBMTxp_xl.lzh:C cc_himenoBMTxp_l.lzh:C \
		cc_himenoBMTxp_m.lzh:C cc_himenoBMTxp_s.lzh:C f90_xp.lzh:F90 himenobmtxpa.lzh:C
DIST_SUBDIR=	himeno

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Himeno bench benchmark, solves Poisson eq. with Jacobi's method

USES=		lha
NO_WRKSUBDIR=	yes

.if defined(WITH_ICC)
BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif

.if defined(WITH_IFC)
USES+=		fortran:ifort
.else
USES+=		fortran
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O2 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
CFLAGS+=	-O2 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.endif

.if defined(WITH_ICC)
CFLAGS_ICC+=	-O3 -tpp7 -axN -Vaxlib
ICC=		${LOCALBASE}/intel_cc_80/bin/icc
PLIST_SUB+=	WITH_ICC=""
.else
PLIST_SUB+=	WITH_ICC="@comment "
.endif
.if defined(WITH_IFC)
FFLAGS_IFC+=	-O3 -tpp7 -axN -Vaxlib -ipo
IFC=		${LOCALBASE}/intel_fc_80/bin/ifort
PLIST_SUB+=	WITH_IFC=""
.else
PLIST_SUB+=	WITH_IFC="@comment "
.endif

.if defined(WITH_IFC)
PLIST_SUB+=	WITH_GFORTRAN="@comment "
.else
PLIST_SUB+=	WITH_GFORTRAN=""
.endif

do-build:
.if ! defined(WITH_IFC)
	cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp    himenobmtxp.f90
.endif
#	cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_xl himenobmtxp_xl.f #Too large
	cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_l  himenobmtxp_l.f
	cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_m  himenobmtxp_m.f
	cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_s  himenobmtxp_s.f
#	cd ${WRKSRC} ; ${CC} ${CFLAGS} -DELARGE  -o himenobmtxps_xl himenobmtxps.c #Too large
	cd ${WRKSRC} ; ${CC} ${CFLAGS} -DLARGE   -o himenobmtxps_l  himenobmtxps.c
	cd ${WRKSRC} ; ${CC} ${CFLAGS} -DMIDDLE  -o himenobmtxps_m  himenobmtxps.c
	cd ${WRKSRC} ; ${CC} ${CFLAGS} -DSMALL   -o himenobmtxps_s  himenobmtxps.c
	cd ${WRKSRC} ; ${CC} ${CFLAGS} -DSSMALL  -o himenobmtxps_ss himenobmtxps.c
	cd ${WRKSRC} ; ${CC} ${CFLAGS}           -o himenobmtxpa    himenobmtxpa.c
.if defined(WITH_IFC)
#	cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_xl.ifc himenobmtxp_xl.f #Too large
	cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_l.ifc  himenobmtxp_l.f
	cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_m.ifc  himenobmtxp_m.f
	cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_s.ifc  himenobmtxp_s.f
	cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp.ifc    himenobmtxp.f90
.endif
.if defined(WITH_ICC)
#	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DELARGE  -o himenobmtxps_xl.icc himenobmtxps.c #Too large
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DLARGE   -o himenobmtxps_l.icc  himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DMIDDLE  -o himenobmtxps_m.icc  himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSMALL   -o himenobmtxps_s.icc  himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSSMALL  -o himenobmtxps_ss.icc himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC}           -o himenobmtxpa.icc    himenobmtxpa.c
.endif
do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_xl          ${PREFIX}/bin #Too large
.if ! defined(WITH_IFC)
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp            ${PREFIX}/bin
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_l           ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_m           ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_s           ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa            ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_l          ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_m          ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_s          ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_ss         ${PREFIX}/bin
.if defined(WITH_IFC)
#	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_xl.ifc      ${PREFIX}/bin #Too large
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_l.ifc       ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_m.ifc       ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_s.ifc       ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp.ifc         ${PREFIX}/bin
.endif
.if defined(WITH_ICC)
#	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_xl.icc     ${PREFIX}/bin #Too large
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_l.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_m.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_s.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_ss.icc     ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa.icc        ${PREFIX}/bin
.endif
.include <bsd.port.post.mk>
