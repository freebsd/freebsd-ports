# Created by: Brion Moss <brion@queeg.com>
# $FreeBSD$

PORTNAME=	xtide
PORTVERSION=	2.13.2
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/ \
		http://www.c-s.li/ports/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${TCD_DISTNAME}-r3${EXTRACT_SUFX} \
		${HARM_DISTNAME}-free${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USES=		gmake
USE_GCC=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I../${TCD_DISTNAME} -I${LOCALBASE}/include/libpng15 -Wno-deprecated-declarations
LDFLAGS+=	-L../${TCD_DISTNAME}/.libs -L${LOCALBASE}/lib

TCD_DISTNAME=	libtcd-2.2.5
HARM_DISTNAME=	harmonics-dwf-20121224
WVS_DISTNAME=	wvs

OPTIONS_DEFINE=	WVS X11
OPTIONS_DEFAULT=X11
WVS_DESC=	Use world vector shoreline data (37MB)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWVS}
DISTFILES+=	${WVS_DISTNAME}${EXTRACT_SUFX}
PLIST_SUB+=	WVS=""
.else
PLIST_SUB+=	WVS="@comment "
.endif

.if ! ${PORT_OPTIONS:MX11}
ALL_TARGET+=	tide xttpd
PLIST_SUB+=	X11="@comment "
.else
USE_XORG+=	xpm xaw
PLIST_SUB+=	X11=""
.endif

post-extract:
	@${LN} -sf ../${HARM_DISTNAME}/${HARM_DISTNAME}-free.tcd ${WRKSRC}/harmonics.tcd

post-patch:
	@${REINPLACE_CMD} -e '/if test/s|==|=|g' ${WRKDIR}/${TCD_DISTNAME}/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Global.cc

pre-configure:
	@cd ${WRKDIR}/${TCD_DISTNAME} \
		&& ${SETENV} ${CONFIGURE_ENV} \
			CC="${CC}" CFLAGS="${CFLAGS}" \
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
			${SH} ./configure --disable-shared \
			${CONFIGURE_ARGS} \
		&& ${MKDIR} ${WRKDIR}/${TCD_DISTNAME}/.libs \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE}

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		< ${FILESDIR}/xtide.conf.example > ${WRKDIR}/xtide.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtide.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/xttpd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tide.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/xttpd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/harmonics.tcd ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/xtide.conf.example ${STAGEDIR}${PREFIX}/etc

post-install:
.if ${PORT_OPTIONS:MWVS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs1.dat ${STAGEDIR}${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs12.dat ${STAGEDIR}${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs250k.dat ${STAGEDIR}${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs3.dat ${STAGEDIR}${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs43.dat ${STAGEDIR}${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvsfull.dat ${STAGEDIR}${DATADIR}/wvs
.endif

.include <bsd.port.mk>
