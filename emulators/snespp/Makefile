# Ports collection makefile for:	snespp
# Date created:		16 April 2007
# Whom:			Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	snespp
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	emulators kld
MASTER_SITES=	http://www.tbrk.org/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kernel module for SNES controllers on a parallel port

BROKEN=	does not compile

KMODDIR=	/boot/modules

NO_PACKAGE=	this port should be recompiled for a particular FreeBSD kernel
PLIST_SUB=	KMODDIR="${KMODDIR}"

MAN4=		snespp.4
MANCOMPRESSED=	no

do-install:
	@${INSTALL_MAN} ${WRKSRC}/snespp.4 ${PREFIX}/man/man4
	@${INSTALL_KLD} ${WRKSRC}/snespp.ko ${KMODDIR}

.include <bsd.port.mk>
