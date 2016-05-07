# $FreeBSD$

PORTNAME=	dump1090_mr
PORTVERSION=	1.15
DISTVERSIONPREFIX= v
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	FlightAware's Mode S decoder for RTLSDR devices

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

MAKE_FLAGS+=	PREFIX="${PREFIX}"

CONFLICTS=	dump1090-*

USES=	gmake pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dump1090 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/view1090 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/public_html
	${MKDIR} ${STAGEDIR}${DATADIR}/public_html/coolclock
	${INSTALL_DATA} ${WRKSRC}/public_html/*.html \
		${STAGEDIR}${DATADIR}/public_html
	${INSTALL_DATA} ${WRKSRC}/public_html/*.js \
		${STAGEDIR}${DATADIR}/public_html
	${INSTALL_DATA} ${WRKSRC}/public_html/*.css \
		${STAGEDIR}${DATADIR}/public_html
	${INSTALL_DATA} ${WRKSRC}/public_html/coolclock/* \
		${STAGEDIR}${DATADIR}/public_html/coolclock

.include <bsd.port.mk>
