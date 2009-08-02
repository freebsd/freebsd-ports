# Ports collection makefile for:	esperanza
# Date created:			23 Feb 2007
# Whom:				Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	esperanza
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	http://exodus.xmms.se/~tru/esperanza/0.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced QT4 XMMS2 client

LIB_DEPENDS=	xmmsclient++.3:${PORTSDIR}/audio/cpp-xmms2

USE_QT_VER=	4
QT_COMPONENTS=	gui xml network imageformats_run \
		qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} --disable-growl
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/esperanza

.include <bsd.port.mk>
