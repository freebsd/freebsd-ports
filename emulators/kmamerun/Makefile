# New ports collection makefile for:	kmamerun
# Date created:				18 January 2003
# Whom:					Scott A. Moberly <smoberly@karamazov.org>
#
# $FreeBSD$

PORTNAME=	kmamerun
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	emulators kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kmamerun

MAINTAINER=	smoberly@karamazov.org
COMMENT=	KDE frontend for M.A.M.E. (Multiple Arcade Machine Emulator)

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USE_KDELIBS_VER=3
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
