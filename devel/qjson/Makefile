# New ports collection makefile for:	qjson
# Date created:				19 December 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	qjson
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt-based library that maps JSON data to QVariant objects

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

WRKSRC=		${WRKDIR}/${PORTNAME}

.ifndef(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_SUFFIX}/data/' \
		-e 's|apps/cmake/modules|cmake/Modules|' \
		${WRKSRC}/CMakeLists.txt

post-build:
.ifndef(NOPORTDOCS)
	cd ${WRKSRC}/doc && doxygen
.endif

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
