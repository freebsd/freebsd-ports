# New ports collection makefile for:   libsidplay
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	libsidplay
PORTVERSION=	1.36.59
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org
COMMENT=	A Commodore SID-chip emulator library to play SID music files

USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if (${ARCH} == i386)
CONFIGURE_ARGS+=	--enable-optendian --enable-optfixpoint
.endif

.include <bsd.port.post.mk>
