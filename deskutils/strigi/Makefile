# New ports collection Makefile for:	strigi
# Date created:				2008-01-11
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	strigi
PORTVERSION=	0.5.11
CATEGORIES=	deskutils
MASTER_SITES=	http://www.vandenoever.info/software/strigi/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Desktop searching program

LIB_DEPENDS=	clucene.0:${PORTSDIR}/textproc/clucene \
		dbus-1:${PORTSDIR}/devel/dbus \
		exiv2:${PORTSDIR}/graphics/exiv2

USE_QT_VER=	4
QT_COMPONENTS=	moc uic qmake gui dbus
USE_BZIP2=	yes
USE_GNOME=	libxml2 pkgconfig
USE_FAM=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes

post-patch:
	${MKDIR} ${WRKSRC}
	${REINPLACE_CMD} -e \
		's,$${LIB_DESTINATION}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/src/streamanalyzer/CMakeLists.txt \
		${WRKSRC}/src/streams/CMakeLists.txt
	${REINPLACE_CMD} -e 's,find_package(Qt4),,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
