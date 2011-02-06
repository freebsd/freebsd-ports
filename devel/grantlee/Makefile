# New ports collection makefile for:	grantlee
# Date created:				2010-10-03
# Whom:					Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	grantlee
PORTVERSION=	0.1.8
CATEGORIES=	devel
MASTER_SITES=	http://www.loegria.net/${PORTNAME}/ \
		http://downloads.${PORTNAME}.org/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	String template engine for Qt4

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network webkit sql phonon \
		qmake_build moc_build rcc_build uic_build
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=FALSE
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	DOCS "Install API documentation" off

.include <bsd.port.pre.mk>

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz
PORTDOCS=	*

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${BUILD_WRKSRC} && ${MAKE} docs
	cd ${BUILD_WRKSRC}/apidox && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
