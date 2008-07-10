# New ports collection makefile for:	qca
# Date created:				27 March 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	qca
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
DISTNAME=	qca-${PORTVERSION}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Cross-platform crypto API for QT

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake gui moc uic rcc qtestlib network
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DQT_QMAKE_EXECUTABLE=${QMAKE}

post-patch:
	${MKDIR} ${WRKSRC}/plugins
	${REINPLACE_CMD} -e \
	's,$${LIB_SUFFIX}/pkgconfig/,data/pkgconfig,' \
	${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
