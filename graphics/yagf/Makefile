# New ports collection makefile for:	graphics/yagf
# Date created:				2009-09-11
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	yagf
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://symmetrica.net/cuneiform-linux/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Graphical interface for the cuneiform OCR program

LIB_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

ONLY_FOR_ARCHS=	i386 amd64

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
INSTALLS_ICONS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui imageformats linguist_build \
		moc_build qmake_build rcc_build uic_build

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>
.if ${OSVERSION}<700042
CMAKE_USE_PTHREAD=	yes
.endif
.include <bsd.port.post.mk>
