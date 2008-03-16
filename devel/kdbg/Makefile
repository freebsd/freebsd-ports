# New ports collection makefile for:	kdbg
# Date created:				02 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	kdbg
PORTVERSION=	2.1.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	conrads@cox.net
COMMENT=	A graphical user interface around gdb using KDE

USE_KDELIBS_VER=	3
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-kde-version=3

.include <bsd.port.mk>
