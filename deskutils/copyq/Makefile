# $FreeBSD$

PORTNAME=	copyq
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	kris@ixsystems.com
COMMENT=	Qt5 based clipboard manager

LICENSE=	GPLv3

USES=		qmake
USE_XORG=	x11 xfixes xtst
USE_QT5=	core gui network svg multimedia imageformats \
		buildtools_build x11extras concurrent widgets xml \
		script
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ

PLIST_FILES=	bin/copyq

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/copyq ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
