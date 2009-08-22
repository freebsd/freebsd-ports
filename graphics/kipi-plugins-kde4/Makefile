# New ports collection makefile for:	kipi-plugins-kde4
# Date created:				Jan 23, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
PORTVERSION=	0.2.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF/kipi/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kris@pcbsd.org
COMMENT=	KDE4 kipi graphics plugins

LIB_DEPENDS=	cv.1:${PORTSDIR}/graphics/opencv \
		expat.6:${PORTSDIR}/textproc/expat2 \
		kipi.6:${PORTSDIR}/graphics/kdegraphics4
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs pimlibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

# Disable IpodExport plugin for now.  Requires audio/libgpod >= 0.7.0.
CMAKE_ARGS=	-DWITH_GLIB2:BOOL=OFF \
		-DWITH_GObject:BOOL=OFF \
		-DWITH_Gdk:BOOL=OFF \
		-DWITH_Gpod:BOOL=OFF

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

.include <bsd.port.mk>
