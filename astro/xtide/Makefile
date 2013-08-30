# Created by: Brion Moss <brion@queeg.com>
# $FreeBSD$

PORTNAME=	xtide
PORTVERSION=	2.13.1
CATEGORIES=	astro geography
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/ \
		http://www.c-s.li/ports/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${TCD_DISTNAME}${EXTRACT_SUFX} \
		${HARM_DISTNAME}-free${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Harmonic tide clock and tide predictor

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USES=		gmake
USE_GCC=	yes
GNU_CONFIGURE=	yes

MAN1=		tide.1
MAN8=		xttpd.8

CPPFLAGS+=	-I../${TCD_DISTNAME} -I${LOCALBASE}/include/libpng15
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
PKGNAMESUFFIX+=	-nox11
ALL_TARGET+=	tide xttpd
PLIST_SUB+=	X11="@comment "
.else
USE_XORG+=	xpm xaw
MAN1+=		xtide.1
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
	${INSTALL_PROGRAM} ${WRKSRC}/tide ${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtide.1 ${MANPREFIX}/man/man1
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/xttpd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tide.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/xttpd.8 ${MAN8PREFIX}/man/man8
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/harmonics.tcd ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/xtide.conf.example ${PREFIX}/etc

post-install:
.if !exists(${PREFIX}/etc/xtide.conf)
	${INSTALL_DATA} ${WRKDIR}/xtide.conf.example ${PREFIX}/etc/xtide.conf
	${CHMOD} 644 ${PREFIX}/etc/xtide.conf
.endif

.if ${PORT_OPTIONS:MWVS}
	@${MKDIR} ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs1.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs12.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs250k.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs3.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs43.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvsfull.dat ${DATADIR}/wvs
.endif

.include <bsd.port.mk>
