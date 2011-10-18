# New ports collection makefile for:	mspdebug
# Date created:				30 Jan 2011
# Whom:					Peter Jeremy <peterjeremy@acm.org>
#
# $FreeBSD$
#
# Based on the OpenBSD port by:		Jasper Lievisse Adriaanse <jasper@openbsd.org>

PORTNAME=		mspdebug
PORTVERSION=		0.17
CATEGORIES=		devel
MASTER_SITES=		SF/${PORTNAME}

MAINTAINER=		peterjeremy@acm.org
COMMENT=		Debugger for use with MSP 430 MCUs

LICENSE=		GPLv2

MAN1=			mspdebug.1
USE_GMAKE=		yes

PLIST_FILES=		bin/mspdebug

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=		usb:${PORTSDIR}/devel/libusb
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mspdebug ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mspdebug.man ${PREFIX}/man/man1/mspdebug.1

.include <bsd.port.post.mk>
