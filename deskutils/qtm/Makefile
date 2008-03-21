# New ports collection makefile for:	qtm
# Date created:		22 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtm
PORTVERSION=	0.5.8.2
CATEGORIES=	deskutils
MASTER_SITES=	SF/catkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog management application based on Qt 4

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui rcc network xml moc_build qmake_build uic_build

MAN1=		qtm.1
PORTDOCS=	Changelog INSTALL README

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} cmake . \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_C_FLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_CXX_FLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_C_LINK_FLAGS="${PTHREAD_LIBS}" \
		-DCMAKE_CXX_LINK_FLAGS="${PTHREAD_LIBS}" \
		-DMANPAGE_DIRECTORY="${MANPREFIX}/man/man1"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
