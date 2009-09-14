# New ports collection makefile for:	graphics/yagf
# Date created:				2009-09-11
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	yagf
PORTVERSION=	0.8.1
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
QT_COMPONENTS=	corelib gui imageformats linguist moc qmake rcc uic

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>
.if ${OSVERSION}<700000
IGNORE=		does not compile at 6.x
.endif
.include <bsd.port.post.mk>
