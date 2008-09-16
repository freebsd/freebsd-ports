# New ports collection makefile for:	quassel
# Date created:		2008-08-10
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quassel
DISTVERSION=	0.3.0.1
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based distributed IRC client

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network script sql dbus xml \
		qmake_build moc_build rcc_build uic_build

CMAKE_USE_PTHREAD=	yes
CMAKE_ARGS+=	-DWANT_MONO=ON

.include <bsd.port.mk>
