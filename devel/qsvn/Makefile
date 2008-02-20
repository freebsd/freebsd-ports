# New ports collection makefile for:	qsvn
# Date created:		2007-11-17
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qsvn
DISTVERSION=	0.6.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel
MASTER_SITES=	http://www.anrichter.net/projects/qsvn/chrome/site/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Qt based GUI frontend for Subversion

BUILD_DEPENDS=	${CMAKE}:${PORTSDIR}/devel/cmake
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build uic_build rcc_build qmake_build qt3support_build
USE_LDCONFIG=	yes
MAKE_ENV+=	VERBOSE=1

DESKTOP_ENTRIES="QSvn" "SVN client" "" "qsvn" "" false

CMAKE?=		${LOCALBASE}/bin/cmake
CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} src

.include <bsd.port.mk>
