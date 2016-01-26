# Created by: Brion Moss <brion@queeg.com>
# $FreeBSD$

PORTNAME=	xtide
PORTVERSION=	2.14
CATEGORIES=	astro geography
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${TCD_DISTNAME}${EXTRACT_SUFX} \
		${HARM_DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USES=		compiler:c++0x gmake libtool localbase tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_tcd_h=yes \
		ac_cv_lib_tcd_get_tide_db_header=yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-deprecated-declarations
CPPFLAGS+=	-I${TCD_WRKSRC} $$(libpng-config --I_opts)
LDFLAGS+=	-L${TCD_WRKSRC}/.libs $$(libpng-config --L_opts)

OPTIONS_DEFINE=		WVS X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

WVS_DESC=		Use world vector shoreline data (37MB)
WVS_DISTFILES=		${WVS_DISTNAME}${EXTRACT_SUFX}
X11_USE=		xorg=xaw,xpm
X11_CONFIGURE_WITH=	x
X11_DESKTOP_ENTRIES=	"XTide" "" "xtide" "xtide" "" ""

TCD_DISTNAME=	libtcd-2.2.6-r2
TCD_WRKSRC=	${WRKDIR}/${TCD_DISTNAME:C/-r[0-9]+//}
HARM_DISTNAME=	harmonics-dwf-20141224-free
HARM_WRKSRC=	${WRKDIR}/${HARM_DISTNAME:C/-free//}
WVS_DISTNAME=	wvs

post-patch:
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=|g' ${TCD_WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|"/etc/|"${PREFIX}/etc/| ; \
		 s| /etc/| ${PREFIX}/etc/|' ${WRKSRC}/libxtide/Global.cc

pre-configure:
	@(cd ${TCD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		CC="${CC}" CFLAGS="${CFLAGS} -fPIC" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" \
		${SH} ./configure ${CONFIGURE_ARGS})

pre-build:
	@(cd ${TCD_WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET})

post-build:
	@${ECHO_CMD} -n > ${WRKDIR}/xtide.conf.sample
	@${ECHO_CMD} "${DATADIR}/harmonics.tcd" >> ${WRKDIR}/xtide.conf.sample
	@${ECHO_CMD} "${DATADIR}/wvs" >> ${WRKDIR}/xtide.conf.sample
	@${LN} -sf ${HARM_DISTNAME}.tcd ${HARM_WRKSRC}/harmonics.tcd
	@${LN} -sf icon_48x48_orig.png ${WRKSRC}/iconsrc/xtide.png

pre-install:
	@(cd ${TCD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install:
	(cd ${WRKDIR} && ${INSTALL_DATA} xtide.conf.sample \
		${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${HARM_WRKSRC} && ${INSTALL_DATA} harmonics.tcd \
		${STAGEDIR}${DATADIR})
post-install-WVS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/wvs
	(cd ${WRKDIR} && ${INSTALL_DATA} wvs*.dat \
		${STAGEDIR}${DATADIR}/wvs)
post-install-X11-on:
	(cd ${WRKSRC}/iconsrc && ${INSTALL_DATA} xtide.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
