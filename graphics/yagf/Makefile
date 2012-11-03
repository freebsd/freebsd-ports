# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yagf
PORTVERSION=	0.9.2
CATEGORIES=	graphics
MASTER_SITES=	http://symmetrica.net/cuneiform-linux/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Graphical interface for the cuneiform OCR program

LIB_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

ONLY_FOR_ARCHS=	i386 amd64

USE_CMAKE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_PKGCONFIG=	build
USE_GNOME=	desktopfileutils
USE_QT4=	corelib gui imageformats linguist_build \
		moc_build qmake_build rcc_build uic_build

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

post-install:
	-update-desktop-database

.include <bsd.port.mk>
