# New ports collection makefile for:	f4l
# Date Created:				2006-05-29
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	f4l
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	editors multimedia www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_beta_swfExport/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source development environment for Macromedia Flash

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES} ${PREFIX}/bin

.include <bsd.port.post.mk>
