# New ports collection makefile for:   kmamerun
# Date created:		24 Nov 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kmamerun
PORTVERSION=	0.3.0.1
CATEGORIES=	emulators kde
MASTER_SITES=	ftp://ftp.sad.it/pub/kde/local/
DISTNAME=	kmamerun-0.3.0pre1

MAINTAINER=	nsayer@freebsd.org

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USE_KDELIBS_VER=1
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)" \
		INSTALL_SCRIPT="install -c -m 555"

.include <bsd.port.mk>
