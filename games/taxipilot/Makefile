# New ports collection makefile for:	taxipilot
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	taxipilot
PORTVERSION=	0.9.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	taxipilot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spacetaxi clone

LIB_DEPENDS=	artsmodules.0:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
EXTRA_PATCHES= ${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}"

.include <bsd.port.mk>
