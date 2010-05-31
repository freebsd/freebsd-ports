# New ports collection makefile for:	kdbg
# Date created:				02 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	kdbg
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	SF/${PORTNAME}/Source%20Code/${PORTVERSION}

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	A graphical user interface around gdb using KDE

USE_KDELIBS_VER=	3
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-kde-version=3

.include <bsd.port.mk>
