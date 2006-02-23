# New ports collection Makefile for:	kpicframer
# Date created:				2004-01-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpicframer
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	http://www.norbs.de/kpicframer/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE card game

LIB_DEPENDS=	kdegames.3:${PORTSDIR}/games/kdegames3

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_AUTOTOOLS=		libtool:15
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-build:
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
