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

# temporarily disable kamera, it requires gphoto2
PLIST_SUB+=	KAMERA:="@comment "

.if defined(WITH_SANE)
LIB_DEPENDS=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_SUB+=	SANE:=""
.else
PLIST_SUB+=	SANE:="@comment "
pre-everything::
	@${ECHO_MSG} "===> If you want to compile this port with scanner support, use \"make WITH_SANE=yes\""
.endif

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--without-kamera

pre-configure:
	${PERL} -pi -e "s@libkscan_la_LIBADD =@libkscan_la_LIBADD= -lintl@g" ${WRKSRC}/libkscan/Makefile.in
	${PERL} -pi -e "s@libkcm_kamera_la_LIBADD =@libkcm_kamera_la_LIBADD= -lintl@g" ${WKRSRC}/kamera/kcontrol/Makefile.in
	${PERL} -pi -e "s@name = item@name=(char*)item@g" ${WRKSRC}/kamera/kcontrol/kamera.cpp
	find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@GPHOTO2_LIBS =@GPHOTO2_LIBS= -lintl@g"

.include <bsd.port.mk>
