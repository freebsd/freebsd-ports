# New ports collection makefile for:	taxipilot
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	taxipilot
PORTVERSION=	0.9.2
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	games kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spacetaxi clone

LIB_DEPENDS=	artsmodules.0:${PORTSDIR}/multimedia/kdemultimedia3

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
EXTRA_PATCHES= ${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-install:
	-${RM} ${PREFIX}/share/apps/taxipilot/game_data/Makefile*

.include <bsd.port.post.mk>
