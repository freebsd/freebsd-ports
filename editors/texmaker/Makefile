# ex:ts=8
# Ports collection makefile for:	texmaker
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texmaker
PORTVERSION=	1.11
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX Development Environment

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		-unix PREFIX="${PREFIX}" texmaker.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texmaker ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/utilities/*.* ${DATADIR}

.include <bsd.port.mk>
