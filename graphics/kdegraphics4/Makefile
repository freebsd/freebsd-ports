# New ports collection makefile for:	KDE2 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	2.2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src

MAINTAINER=	will@FreeBSD.org

BUILD_DEPENDS=	dvips:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	dvips:${PORTSDIR}/print/teTeX

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@libkscan_la_LIBADD =@libkscan_la_LIBADD= -lintl@g" ${WRKSRC}/libkscan/Makefile.in
	${PERL} -pi -e "s@libkcm_kamera_la_LIBADD =@libkcm_kamera_la_LIBADD= -lintl@g" ${WKRSRC}/kamera/kcontrol/Makefile.in
	${PERL} -pi -e "s@name = item@name=(char*)item@g" ${WRKSRC}/kamera/kcontrol/kamera.cpp
	find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@GPHOTO2_LIBS =@GPHOTO2_LIBS= -lintl@g"

.include <bsd.port.mk>
