# New ports collection makefile for:	snotes
# Date Created:				2006-04-27
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	snotes
PORTVERSION=	1.1.5
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	s-notes

MAINTAINER=	shaun@inerd.com
COMMENT=	A lightweight, configurable sticky notes utility

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_X_PREFIX=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake -project
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake -nocache

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
