# New ports collection makefile for:	qjackctl
# Date created:		2006-12-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	qjackctl
PORTVERSION=	0.2.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qjackctl

MAINTAINER=	trasz@freebsd.org
COMMENT=	Qt Interface for the JACK Audio Connection Kit

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ARGS+=	QTDIR="${QT_PREFIX}" CXXFLAGS="${CFLAGS} -pthread"
MAKE_ENV=	QTDIR="${QT_PREFIX}" MAKE="${GMAKE}" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"

.include <bsd.port.mk>
