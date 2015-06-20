# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kuickshow
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	7
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE image viewer

BROKEN=		depends on imlib
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-07-21

USE_GNOME=	imlib
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	corelib opengl qmake_build moc_build rcc_build uic_build
USES=		cmake gettext pkgconfig tar:bzip2

APP_VER=	0.9.1
EXTRA_VER=	4.4.0

.include <bsd.port.mk>
