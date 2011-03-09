# New ports collection makefile for:	libalkimia
# Date created:				2011-02-28
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libalkimia
PORTVERSION=	4.3.0
CATEGORIES=	finance kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	137323-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Financial data handling library for KDE4

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build

LICENSE=	LGPL21

MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:

	@${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|' \
			  -e 's|KDE4_INCLUDE_DIR|INCLUDE_INSTALL_DIR|g' \
			  -e 's|KDE4_LIB_DIR|LIB_INSTALL_DIR|g' \
				${WRKSRC}/CMakeLists.txt \
				${WRKSRC}/libalkimia.pc.in

.include <bsd.port.mk>
