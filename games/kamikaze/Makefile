# New ports collection makefile for:	kamikaze
# Date created:				06 August 2005
# Whom:					Josef Spillner <spillner@kde.org>
#
# $FreeBSD$

PORTNAME=	kamikaze
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://kamikaze.coolprojects.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer bomberman-style game for KDE

LICENSE=	GPLv2

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-server
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

MAN6=		kamikaze.6 kamikaze-editor.6

.include <bsd.port.mk>
