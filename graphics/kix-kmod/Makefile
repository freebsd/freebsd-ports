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

SYSDIR?=	${SRC_BASE}/sys
.if !exists(${SYSDIR}/dev/syscons/syscons.h)
IGNORE=		Requires kernel source (/usr/src/sys) to build
.endif
MAKE_ENV+=	WERROR=
PLIST_FILES=	lib/kix_saver.ko

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kix_saver.ko ${PREFIX}/lib

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
