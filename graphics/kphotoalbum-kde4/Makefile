# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kphotoalbum
PORTVERSION=	4.3
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		exiv2:${PORTSDIR}/graphics/exiv2

USE_KDE4=	kdehier kdelibs kdeprefix libkdcraw libkipi automoc4
USE_QT4=	corelib qt3support \
		qmake_build moc_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=	MARBLE
OPTIONS_DEFAULT=MARBLE

MARBLE_DESC=	Geolocation support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMARBLE}
USE_KDE4+=	marble
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=Off
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=Off
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
