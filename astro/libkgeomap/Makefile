# New ports collection makefile for:	libkgeomap
# Date created:				2012-05-12
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libkgeomap
PORTVERSION=	2.7.0
CATEGORIES=	astro kde
MASTER_SITES=	SF/digikam/digikam/${PORTVERSION}
DISTNAME=	digikam-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for browsing photos on a map

LICENSE=	GPLv2

OPTIONS_DEFINE=	NLS

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs libkexiv2 marble
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/extra/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DWITH_NLS:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		${WRKSRC}/CMakeLists.txt
	${LN} -s ../../po ${WRKSRC}/po
	${RM} ${WRKSRC}/po/*/digikam.po ${WRKSRC}/po/*/kipi*

.include <bsd.port.mk>
