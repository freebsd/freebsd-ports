# New ports collection Makefile for:	kpicframer
# Date created:				2004-01-25
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpicframer
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://www.norbs.de/kpicframer/download/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	KDE card game

USE_KDELIBS_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-build:
	${TOUCH} ${WRKSRC}/config.h.in

.include <bsd.port.mk>
