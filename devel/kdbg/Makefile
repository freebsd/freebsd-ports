# New ports collection makefile for:	kdbg
# Date created:				02 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	kdbg
PORTVERSION=	1.2.5
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= kdbg/
USE_QT_VER=	3
USE_KDELIBS_VER=3

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	A graphical user interface around gdb using KDE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBQTMT="-lqt-mt" \
		CXXFLAGS=-pthread

CONFIGURE_ARGS=	--with-kde-version=3

.include <bsd.port.mk>
