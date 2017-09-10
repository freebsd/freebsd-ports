# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	himenobench
PORTVERSION=	2015.07.09
PORTREVISION=	4
CATEGORIES=	benchmarks
MASTER_SITES=	http://accc.riken.jp/wp-content/uploads/2015/07/
DISTFILES=	himenobmtxp_xl.zip himenobmtxp_l.zip \
		himenobmtxp_m.zip himenobmtxp_s.zip \
		cc_himenobmtxp_xl.zip cc_himenobmtxp_l.zip \
		cc_himenobmtxp_m.zip cc_himenobmtxp_s.zip \
		f90_xp.zip himenobmtxpa.zip
DIST_SUBDIR=	himeno

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for measureing performance of floating point operation

LICENSE=	LGPL20 # (or later)

EXTRACT_DEPENDS=	lha:archivers/lha

USES=		dos2unix fortran zip
DOS2UNIX_GLOB=	*.c *.f
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=		ICC OPTIMIZED_CFLAGS
OPTIONS_SUB=		yes

ICC_DESC=		Intel C compiler support
ICC_BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:lang/icc
OPTIMIZED_CFLAGS_CFLAGS=${OPTFLAGS}
OPTIMIZED_CFLAGS_VARS=	FFLAGS+="${OPTFLAGS}"

ICC=		${LOCALBASE}/intel_cc_80/bin/icc
CFLAGS_ICC=	-O3 -tpp7 -axN -Vaxlib
OPTFLAGS=	-O2 -ffast-math -finline-functions -fomit-frame-pointer \
		-funroll-loops -fexpensive-optimizations

post-extract:
	@${FIND} ${WRKSRC} -name "*.lzh" -type f -maxdepth 1 -exec lha \
		xfpw=${WRKSRC} {} \;

do-build:
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
	cd ${WRKSRC} ; ${FC} ${FFLAGS} -o himenobmtxp    himenobmtxp.f90

do-build-ICC-on:
#	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DELARGE  -o himenobmtxps_xl.icc himenobmtxps.c #Too large
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DLARGE   -o himenobmtxps_l.icc  himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DMIDDLE  -o himenobmtxps_m.icc  himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSMALL   -o himenobmtxps_s.icc  himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC} -DSSMALL  -o himenobmtxps_ss.icc himenobmtxps.c
	cd ${WRKSRC} ; ${ICC} ${CFLAGS_ICC}           -o himenobmtxpa.icc    himenobmtxpa.c

do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_xl          ${STAGEDIR}${PREFIX}/bin #Too large
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_l          ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_m          ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp_s          ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa           ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_l         ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_m         ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_s         ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_ss        ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxp            ${STAGEDIR}${PREFIX}/bin

do-install-ICC-on:
#	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_xl.icc    ${STAGEDIR}${PREFIX}/bin #Too large
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_l.icc     ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_m.icc     ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_s.icc     ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxps_ss.icc    ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/himenobmtxpa.icc       ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
