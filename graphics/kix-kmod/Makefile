# New ports collection makefile for:	kix-kmod
# Date created:				4 January 2003
# Whom:					Jonathan Belson <jon@witchspace.com>
#
# $FreeBSD$
#

PORTNAME=       kix
PORTVERSION=	1.0
CATEGORIES=     graphics
MASTER_SITES=   http://www.witchspace.com/files/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	jon@witchspace.com
COMMENT=	A graphical screensaver kernel module

.if !exists(/usr/src/sys/dev/syscons/syscons.h)
BROKEN=		"Requires kernel source (/usr/src/sys) to build"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kix_saver.ko ${PREFIX}/lib

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
