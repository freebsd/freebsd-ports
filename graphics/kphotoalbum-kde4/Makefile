# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kphotoalbum
PORTVERSION=	4.4
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		exiv2:${PORTSDIR}/graphics/exiv2

USE_KDE4=	kdehier kdelibs kdeprefix libkdcraw libkipi automoc4
USE_QT4=	phonon sql \
		qmake_build moc_build rcc_build uic_build
USE_BZIP2=	yes
USES=		cmake:outsource

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=	MARBLE
OPTIONS_DEFAULT=MARBLE

MARBLE_DESC=	Geolocation support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMARBLE}
USE_KDE4+=	marble
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=Off
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=Off
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
