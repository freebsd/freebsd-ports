# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
PORTVERSION=	0.10.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF

MAINTAINER=	datahead4@gmail.com
COMMENT=	An advanced digital photo management application for KDE4

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.5:${PORTSDIR}/graphics/png \
		jasper.4:${PORTSDIR}/graphics/jasper \
		kipi.6:${PORTSDIR}/graphics/kdegraphics4

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network qt3support sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_GNOME=	pkgconfig
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

MAN1=		digitaglinktree.1

OPTIONS=	GPHOTO2 "Compile with gphoto2 support" on \
		LENSFUN "Compile lens auto-correction image editor plugin" off \
		MARBLE "Geolocation support (requires misc/kdeedu4)" off \
		PIMLIBS "Address book support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GPHOTO2)
CMAKE_ARGS+=	-DENABLE_GPHOTO2:BOOL=OFF
.else
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
.endif

.if defined(WITH_LENSFUN)
LIB_DEPENDS+=	lensfun.0:${PORTSDIR}/graphics/lensfun
.else
CMAKE_ARGS+=	-DWITH_LensFun:BOOL=OFF
.endif

.if defined(WITH_MARBLE)
LIB_DEPENDS+=	marblewidget.5:${PORTSDIR}/misc/kdeedu4
.else
CMAKE_ARGS+=	-DWITH_MarbleWidget:BOOL=OFF
.endif

.if defined(WITHOUT_PIMLIBS)
CMAKE_ARGS+=	-DWITH_KdepimLibs:BOOL=OFF
.else
USE_KDE4+=	pimlibs
.endif

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

.include <bsd.port.post.mk>
