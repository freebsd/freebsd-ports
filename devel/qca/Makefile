# New ports collection makefile for:	qca
# Date created:				27 March 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	qca
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
DISTNAME=	qca-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform crypto API for QT

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qtestlib network qmake_build \
		moc_build uic_build rcc_build
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DQT_QMAKE_EXECUTABLE=${QMAKE}

.include <bsd.port.mk>
