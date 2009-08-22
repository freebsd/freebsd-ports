# New ports collection makefile for:	libggigcp
# Date created:				7 December 2004
# Whom:					antoine.brodin@laposte.net
#
# $FreeBSD$
#

PORTNAME=	libggigcp
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.ggi-project.org/ftp/ggi/v2.2/ \
		SF/ggi/misc/${PORTNAME}-${PORTVERSION}		

DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine.brodin@laposte.net
COMMENT=	A libggi extension for advanced color and palette handling

LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

MAN3=		gcpBlendColor.3 \
		gcpGetLuminance.3 \
		gcpGetRGBAGamma.3 \
		gcpInit.3 \
		gcpMapRGBAColor.3 \
		gcpSetColorfulPalette.3 \
		gcpSetIntensity.3 \
		gcpSetRGBAPalette.3 \
		gcpUnmapRGBAPixel.3 \
		gcp_pixel.3
MAN7=		libggigcp.7
MLINKS=		gcpGetRGBAGamma.3 gcpGetCMYKGamma.3 \
		- gcpGetCMYKGammaMap.3 - gcpGetHSVGamma.3 \
		- gcpGetHSVGammaMap.3 - gcpGetRGBAGammaMap.3 \
		- gcpGetYCCGamma.3 - gcpGetYCCGammaMap.3 \
		- gcpGetYUVGamma.3 - gcpGetYUVGammaMap.3 \
		- gcpSetCMYKGamma.3 - gcpSetCMYKGammaMap.3 \
		- gcpSetHSVGamma.3 - gcpSetHSVGammaMap.3 \
		- gcpSetRGBAGamma.3 - gcpSetRGBAGammaMap.3 \
		- gcpSetYCCGamma.3 - gcpSetYCCGammaMap.3 \
		- gcpSetYUVGamma.3 - gcpSetYUVGammaMap.3 \
		gcpInit.3 gcpAttach.3 \
		- gcpDetach.3 - gcpExit.3 \
		gcpMapRGBAColor.3 gcpMapCMYKColor.3 \
		- gcpMapHSVColor.3 - gcpMapYCCColor.3 \
		- gcpMapYUVColor.3 - gcpPackCMYKColors.3 \
		- gcpPackHSVColors.3 - gcpPackRGBAColors.3 \
		- gcpPackYCCColors.3 - gcpPackYUVColors.3 \
		gcpSetIntensity.3 gcpGetIntensity.3 \
		gcpSetRGBAPalette.3 gcpGetCMYKPalette.3 \
		- gcpGetHSVPalette.3 - gcpGetRGBAPalette.3 \
		- gcpGetYCCPalette.3 - gcpGetYUVPalette.3 \
		- gcpSetCMYKPalette.3 - gcpSetHSVPalette.3 \
		- gcpSetYCCPalette.3 - gcpSetYUVPalette.3 \
		gcpUnmapRGBAPixel.3 gcpUnmapCMYKPixel.3 \
		- gcpUnmapHSVPixel.3 - gcpUnmapYCCPixel.3 \
		- gcpUnmapYUVPixel.3 - gcpUnpackCMYKPixels.3 \
		- gcpUnpackHSVPixels.3 - gcpUnpackRGBAPixels.3 \
		- gcpUnpackYCCPixels.3 - gcpUnpackYUVPixels.3 \
		gcp_pixel.3 gcp_CMYKcolor.3 \
		- gcp_HSVcolor.3 - gcp_RGBAcolor.3 \
		- gcp_YCCcolor.3 - gcp_YUVcolor.3

post-install:
	${INSTALL_DATA} ${WRKSRC}/libggigcp.conf ${PREFIX}/etc/ggi/libggigcp.conf.dist

.include <bsd.port.mk>
