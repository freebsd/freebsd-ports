# New ports collection makefile for:	guiloader-c++
# Date created:		11 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	guiloader-c++
PORTVERSION=	2.17.1
CATEGORIES=	devel gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ binding to the GuiLoader library

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	guiloader.1:${PORTSDIR}/devel/guiloader \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

PROJECTHOST=	nothing-personal
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-hidden-visibility
USE_LDCONFIG=	yes

.include <bsd.port.mk>
