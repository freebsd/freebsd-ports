# New ports collection makefile for:   kmamerun
# Date created:		24 Nov 1999
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kmamerun
PORTVERSION=	1.0.0
CATEGORIES=	emulators kde
MASTER_SITES=	ftp://ftp.sad.it/pub/kde/local/

MAINTAINER=	ports@freebsd.org

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame

USE_KDELIBS_VER=1
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
