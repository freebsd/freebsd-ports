# Created by: Julian Jenkins <kaveman@magna.com.au>
# $FreeBSD$

PORTNAME=	spice
PORTVERSION=	3f5.2
PORTREVISION=	12
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/pubs/downloads/spice/:srcs \
		http://www-device.eecs.berkeley.edu/~bsim/Files/BSIM3/ftpv330/src/:bsim3 \
		http://www-device.eecs.berkeley.edu/~bsim/Files/BSIM4/BSIM480/:bsim4 \
		http://home.hiroshima-u.ac.jp/usdl/HiSIM2/:hisim2 \
		LOCAL/hrs/${PORTNAME}:docs
DISTFILES=	spice3f5${EXTRACT_SUFX}:srcs \
		BSIM3v330.tar.Z:bsim3 \
		BSIM480_Code.zip:bsim4 \
		HiSIM_2.8.0_Release_20140605.zip:hisim2 \
		cp.ps:docs toc.ps:docs doc.ps:docs
DIST_SUBDIR=	spice
EXTRACT_ONLY=	spice3f5${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	General-purpose circuit simulation program

BROKEN=		unfetchable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

EXTRACT_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip

BROKEN_aarch64=	Fails to link: missing sbrk

WRKSRC=		${WRKDIR}/${PORTNAME}3f5
MAKEFILE=	${FILESDIR}/Makefile
CONFIGURE_ENV=	CONFIGFILE="${CONFIGFILE}" \
		LOCALBASE="${LOCALBASE}"
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	spice3f3.ps.gz
PORTEXAMPLES=	bjtnoise.cir bsim1tst.cir bsim2tst.cir diffpair.cir \
		diodisto.cir ltra_1.cir ltra_2.cir ltra_3.cir \
		mixdisto.cir mos6inv.cir mosamp2.cir mosmem.cir process.mod \
		process.pro pz2.cir pzt.cir rc.cir rca3040.cir resnoise.cir \
		rtlinv.cir schmitt.cir simplepz.cir

OPTIONS_DEFINE=	DOCS EXAMPLES X11 DEV_BSIM3 DEV_BSIM4 DEV_HISIM2
OPTIONS_DEFAULT=X11

X11_USES=		xorg
X11_USE=		XORG=x11,xaw,xext,xmu,xt
X11_CONFIGURE_ENV=	WITH_X11=yes
DEV_BSIM3_DESC=		BSIM3v3 MOS Transistor Model Support
DEV_BSIM3_LICENSE=	BSIML
DEV_BSIM3_LICENSE_FILE=	${WRKSRC}/src/lib/dev/bsim3/B3TERMS_OF_USE
DEV_BSIM4_DESC=		BSIM4v4 MOS Transistor Model Support
DEV_BSIM4_LICENSE=	BSIML
DEV_BSIM4_LICENSE_FILE=	${WRKSRC}/src/lib/dev/bsim4/B4TERMS_OF_USE.txt
DEV_HISIM2_DESC=	HiSIM2 IGFET Model Support
DEV_HISIM2_LICENSE=	HISIML

.include <bsd.port.options.mk>

# Configuration parameters.
CC_OPT=		${CFLAGS}
CONFIGFILE=	${WRKSRC}/conf/FreeBSD
DEVICES=

LICENSE_FILE_MIT=	${WRKSRC}/COPYRIGHT
LICENSE_NAME_BSIML=	BSIM license
LICENSE_PERMS_BSIML=	dist-mirror pkg-mirror auto-accept
LICENSE_NAME_HISIML=	HiSIM license
LICENSE_PERMS_HISIML=	dist-mirror pkg-mirror auto-accept
LICENSE_FILE_HISIML=	${FILESDIR}/hisim2-license.txt

.for D in ${OPTIONS_DEFINE:MDEV_*:S/DEV_//}
. if !empty(PORT_OPTIONS:MDEV_$D)
LICENSE_COMB=	multi
DEVICES+=	${D:tl}
.  if  !empty(DEV_${D}_LICENSE)
LICENSE+=	${DEV_${D}_LICENSE}
.   if  !empty(DEV_${D}_LICENSE_FILE)
LICENSE_FILE_${DEV_${D}_LICENSE}=	${DEV_${D}_LICENSE_FILE}
.   endif
.  endif
. endif
.endfor
LICENSE:=	${LICENSE:O:u}

post-extract:
	@${DO_NADA}
post-extract-DEV_BSIM3-on:
	@${MKDIR} ${WRKSRC}/src/lib/dev/bsim3
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/BSIM3v330.tar.Z \
	    -C ${WRKSRC}/src/lib/dev/bsim3
post-extract-DEV_BSIM4-on:
	@${MKDIR} ${WRKSRC}/src/lib/dev/bsim4
	${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/BSIM480_Code.zip \
	    -d ${WRKSRC}/src/lib/dev/bsim4
post-extract-DEV_HISIM2-on:
	${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/HiSIM_2.8.0_Release_20140605.zip \
	    -d ${WRKDIR}
	${MV} ${WRKDIR}/HiSIM_2.8.0_Release_20140605/HiSIM_2.8.0_C-Code/hisim2 \
	    ${WRKSRC}/src/lib/dev

${CONFIGFILE}::
	@${SETENV} ${CONFIGURE_ENV} ${MAKE} -f ${MAKEFILE} configure
.for V in CC MAKE CC_OPT
	@${ECHO_CMD} "${V}=${$V}" >> ${WRKSRC}/conf/FreeBSD
.endfor
.for V in DEVICES
	@${ECHO_CMD} "${V}+=${$V}" >> ${WRKSRC}/conf/FreeBSD
.endfor

do-configure: ${CONFIGFILE}
	@${DO_NADA}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/*.ps | ${GZIP_CMD} > \
	    ${STAGEDIR}${DOCSDIR}/${PORTDOCS}
post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	    ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
