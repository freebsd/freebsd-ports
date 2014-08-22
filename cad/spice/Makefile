# Created by: Julian Jenkins <kaveman@magna.com.au>
# $FreeBSD$

PORTNAME=	spice
PORTVERSION=	3f5.2
PORTREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/pubs/downloads/spice/:srcs \
		http://www-device.eecs.berkeley.edu/~bsim/Files/BSIM3/ftpv330/src/:bsim3 \
		http://www-device.eecs.berkeley.edu/~bsim/Files/BSIM4/BSIM480/:bsim4 \
		LOCAL/hrs/${PORTNAME}:docs
DISTFILES=	spice3f5${EXTRACT_SUFX}:srcs \
		BSIM3v330.tar.Z:bsim3 \
		BSIM480_Code.zip:bsim4 \
		cp.ps:docs toc.ps:docs doc.ps:docs
DIST_SUBDIR=	spice
EXTRACT_ONLY=	spice3f5${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	General-purpose circuit simulation program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

EXTRACT_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME}3f5
MAKEFILE=	${FILESDIR}/Makefile
CONFIGURE_ENV=	CONFIGFILE="${WRKSRC}/conf/FreeBSD" \
		LOCALBASE="${LOCALBASE}"

PORTDOCS=	spice3f3.ps.gz
PORTEXAMPLES=	bjtnoise.cir bsim1tst.cir bsim2tst.cir diffpair.cir \
		diodisto.cir ltra_1.cir ltra_2.cir ltra_3.cir \
		mixdisto.cir mos6inv.cir mosamp2.cir mosmem.cir process.mod \
		process.pro pz2.cir pzt.cir rc.cir rca3040.cir resnoise.cir \
		rtlinv.cir schmitt.cir simplepz.cir

OPTIONS_DEFINE=	DOCS EXAMPLES X11 DEV_BSIM3 DEV_BSIM4
OPTIONS_DEFAULT=DOCS EXAMPLES X11

X11_USE=		XORG=x11,xaw,xext,xmu,xt
X11_CONFIGURE_ENV=	WITH_X11=yes
DEV_BSIM3_DESC=		BSIM3v3 MOS Transistor Model Support
DEV_BSIM3_CONFIGURE_ENV=DEV_BSIM3=yes
DEV_BSIM4_DESC=		BSIM4v4 MOS Transistor Model Support
DEV_BSIM4_CONFIGURE_ENV=DEV_BSIM4=yes

.include <bsd.port.options.mk>

post-extract:
	@${DO_NADA}
.if ${PORT_OPTIONS:MDEV_BSIM3}
	@${MKDIR} ${WRKSRC}/src/lib/dev/bsim3
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/BSIM3v330.tar.Z \
	    -C ${WRKSRC}/src/lib/dev/bsim3
.endif
.if ${PORT_OPTIONS:MDEV_BSIM4}
	@${MKDIR} ${WRKSRC}/src/lib/dev/bsim4
	${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/BSIM480_Code.zip \
	    -d ${WRKSRC}/src/lib/dev/bsim4
.endif

do-configure:
	@${SETENV} ${CONFIGURE_ENV} ${MAKE} -f ${MAKEFILE} configure
	@(${ECHO_CMD} "CC=	${CC}";		\
	  ${ECHO_CMD} "MAKE=	${MAKE}";	\
	  ${ECHO_CMD} "CC_OPT=	${CFLAGS}";	\
	) >> ${WRKSRC}/conf/FreeBSD

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/*.ps | ${GZIP_CMD} > \
	    ${STAGEDIR}${DOCSDIR}/${PORTDOCS}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	    ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
