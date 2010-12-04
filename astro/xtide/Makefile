# New ports collection makefile for:   xtide
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	xtide
PORTVERSION=	2.11
PORTREVISION=	2
CATEGORIES=	astro geography
MASTER_SITES=	ftp://ftp.flaterco.com/xtide/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${TCD_DISTNAME}${EXTRACT_SUFX} \
		${HARM_DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	c-s@c-s.li
COMMENT=	Harmonic tide clock and tide predictor

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		tide.1
MAN8=		xttpd.8

CPPFLAGS=	-I../${TCD_DISTNAME} -I${LOCALBASE}/include/libpng
LDFLAGS=	-L../${TCD_DISTNAME}/.libs -L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

TCD_DISTNAME=	libtcd-2.2.5
HARM_DISTNAME=	harmonics-dwf-20100529-free
WVS_DISTNAME=	wvs

OPTIONS=	WVS "Use world vector shoreline data (big file!)" Off

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WVS)
DISTFILES+=	${WVS_DISTNAME}${EXTRACT_SUFX}
PLIST_SUB+=	WVS=""
.else
PLIST_SUB+=	WVS="@comment "
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
ALL_TARGET=	tide xttpd
PLIST_SUB+=	X11="@comment "
.else
USE_XORG=	xpm xaw
MAN1+=		xtide.1
PLIST_SUB+=	X11=""
.endif

post-extract:
	@${LN} -sf ../${HARM_DISTNAME}.tcd ${WRKSRC}/harmonics.tcd

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
.if !defined(WITHOUT_X11)
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

.if !defined(WITHOUT_WVS)
	@${MKDIR} ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs1.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs12.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs250k.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs3.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvs43.dat ${DATADIR}/wvs
	${INSTALL_DATA} ${WRKDIR}/wvsfull.dat ${DATADIR}/wvs
.endif

.include <bsd.port.post.mk>
