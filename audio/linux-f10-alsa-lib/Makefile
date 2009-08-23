# New ports collection makefile for:	audio/linux-f10-alsa-lib
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	alsa-lib
PORTVERSION=	1.0.20
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The Advanced Linux Sound Architecture libraries (Linux Fedora 10)

CONFLICTS=	linux-alsa-lib-[0-9]* linux-f8-alsa-lib-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
BRANDELF_FILES=	usr/bin/aserver
USE_LDCONFIG=	yes

.include <bsd.port.mk>
