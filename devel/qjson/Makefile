# New ports collection makefile for:	qjson
# Date created:				19 December 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	qjson
PORTVERSION=	0.7.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt-based library that maps JSON data to QVariant objects

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_SUFFIX}/data/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
