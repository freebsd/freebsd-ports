# New ports collection makefile for:	firmware-utils
# Date created:			2011-12-22
# Whom:				Stefan Bethke <stb@lassitu.de>
#
# $FreeBSD$
#

PORTNAME=	firmware-utils
PORTVERSION=	20111222
CATEGORIES=	devel
MASTER_SITES=	http://www.transit.hanse.de/mirror/svn.openwrt.org/firmware-utils/

MAINTAINER=	stb@assitu.de
COMMENT=	Create device firmware images

USE_BZIP2=	yes

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ARGS+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" PREFIX=${PREFIX}

.include <bsd.port.mk>
