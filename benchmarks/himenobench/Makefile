# New ports collection makefile for:   himenobench
# Date Created:                16 Aug 2004
# Whom:                        NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	himenobench
PORTVERSION=	2004.08.16
CATEGORIES=	benchmarks
MASTER_SITES=	http://accc.riken.jp/HPC/HimenoBMT/Load_module/
DISTFILES=	himenoBMTxp_xl.lzh himenoBMTxp_l.lzh himenoBMTxp_m.lzh himenoBMTxp_s.lzh \
		cc_himenoBMTxp_xl.lzh himenoBMTxpa.lzh f90_xp.lzh
DIST_SUBDIR=	himeno

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Himeno bench benchmark, solves Poisson eq. with Jacobi's method

.if defined(USE_ICC)
BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif
.if defined(USE_IFC)
BUILD_DEPENDS=	${LOCALBASE}/intel_fc_80/bin/ifort:${PORTSDIR}/lang/ifc
.endif
EXTRACT_DEPENDS=	lha:${PORTSDIR}/archivers/lha

NO_CDROM=	"unsure to sell for profit"
NO_PACKAGE=	"unsure to redistribute"

.if defined(OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll -loops -fexpensive-optimizations -malign-double
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll -loops -fexpensive-optimizations -malign-double
.if (${MACHINE_ARCH} == "i386")
CFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3
CXXFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

.if defined(USE_ICC)
CFLAGS_ICC+=	-O3 -tpp7 -xiMKW -Vaxlib
ICC=		${LOCALBASE}/intel_cc_80/bin/icc
PLIST_SUB+=	USE_ICC=""
.else
PLIST_SUB+=	USE_ICC="@comment "
.endif
.if defined(USE_IFC)
FFLAGS_IFC+=	-O3 -tpp7 -xiMKW -Vaxlib -ipo
IFC=		${LOCALBASE}/intel_fc_80/bin/ifort
PLIST_SUB+=	USE_IFC=""
.else
PLIST_SUB+=	USE_IFC="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@for i in ${DISTFILES}; do \
	cd ${WRKSRC} ; lha x ${DISTDIR}/${DIST_SUBDIR}/$$i; \
	done
do-build:
#	@cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_xl himenobmtxp_xl.f #Too large
	@cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_l  himenobmtxp_l.f
	@cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_m  himenobmtxp_m.f
	@cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp_s  himenobmtxp_s.f
#	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DELARGE  -o himenobmtxps_xl himenobmtxps.c #Too large
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DLARGE   -o himenobmtxps_l  himenobmtxps.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DMIDDLE  -o himenobmtxps_m  himenobmtxps.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DSMALL   -o himenobmtxps_s  himenobmtxps.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DSSMALL  -o himenobmtxps_ss himenobmtxps.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DELARGE  -o himenobmtxpa_xl himenobmtxpa.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DLARGE   -o himenobmtxpa_l  himenobmtxpa.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DMIDDLE  -o himenobmtxpa_m  himenobmtxpa.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DSMALL   -o himenobmtxpa_s  himenobmtxpa.c
	@cd ${WRKSRC} ; ${CC} ${CFLAGS} -DSSMALL  -o himenobmtxpa_ss himenobmtxpa.c
.if defined(USE_IFC)
#	@cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_xl.ifc himenobmtxp_xl.f #Too large
	@cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_l.ifc  himenobmtxp_l.f
	@cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_m.ifc  himenobmtxp_m.f
	@cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp_s.ifc  himenobmtxp_s.f
	@cd ${WRKSRC} ; ${IFC} ${FFLAGS_IFC} -o himenobmtxp.ifc    himenobmtxp.f90
.endif
.if defined(USE_ICC)
#	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DELARGE  -o himenobmtxps_xl.icc himenobmtxps.c #Too large
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DLARGE   -o himenobmtxps_l.icc  himenobmtxps.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DMIDDLE  -o himenobmtxps_m.icc  himenobmtxps.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSMALL   -o himenobmtxps_s.icc  himenobmtxps.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSSMALL  -o himenobmtxps_ss.icc himenobmtxps.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DELARGE  -o himenobmtxpa_xl.icc himenobmtxpa.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DLARGE   -o himenobmtxpa_l.icc  himenobmtxpa.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DMIDDLE  -o himenobmtxpa_m.icc  himenobmtxpa.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSMALL   -o himenobmtxpa_s.icc  himenobmtxpa.c
	@cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSSMALL  -o himenobmtxpa_ss.icc himenobmtxpa.c
.endif
do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_xl          ${PREFIX}/bin #Too large
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_l           ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_m           ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_s           ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_l          ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_m          ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_s          ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_ss         ${PREFIX}/bin
#	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_xl.ifc      ${PREFIX}/bin #Too large
.if defined(USE_IFC)
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_l.ifc       ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_m.ifc       ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_s.ifc       ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp.ifc         ${PREFIX}/bin
.endif
.if defined(USE_ICC)
#	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_xl.icc     ${PREFIX}/bin #Too large
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_l.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_m.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_s.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_ss.icc     ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa_xl.icc     ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa_l.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa_m.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa_s.icc      ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa_ss.icc     ${PREFIX}/bin
.endif
.include <bsd.port.mk>
