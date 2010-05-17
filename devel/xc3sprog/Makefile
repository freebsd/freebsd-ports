# New ports collection makefile for:	xc3sprog
# Date created:		15 May 2010
# Whom:			Wojciech A. Koszek <wkoszek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xc3sprog
PORTVERSION=	r449
CATEGORIES=	devel
MASTER_SITES=	http://FreeBSD.czest.pl/~wkoszek/ports/

MAINTAINER=	wkoszek@FreeBSD.org
COMMENT=	Free programmer for Xilinx Spartan S3E Starter Kit

LIB_DEPENDS=	ftdi:${PORTSDIR}/devel/libftdi
RUN_DEPENDS=	${LOCALBASE}/sbin/fxload:${PORTSDIR}/misc/fxload

USE_CMAKE=	yes
ALL_TARGET=	xc3sprog

PLIST_FILES=	bin/xc3sprog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xc3sprog ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800069)
BROKEN=	doesn't build on FreeBSD prior libusb(8) integration to base system
.endif

.include <bsd.port.post.mk>
