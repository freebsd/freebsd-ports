# New ports collection makefile for:	guiloader-c++
# Date created:		11 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	guiloader-c++
PORTVERSION=	2.10.1
CATEGORIES=	devel gnome
MASTER_SITES=	SF/crow-designer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ binding to the GuiLoader library

BUILD_DEPENDS=	guiloader>=2.10.1:${PORTSDIR}/devel/guiloader
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	guiloader>=2.10.1:${PORTSDIR}/devel/guiloader

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
