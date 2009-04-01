# New ports collection makefile for:	audio/linux-f8-alsa-lib
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	alsa-lib
PORTVERSION=	1.0.15
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The Advanced Linux Sound Architecture libraries (Linux Fedora 8)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
BRANDELF_FILES=	usr/bin/aserver
USE_LDCONFIG=	yes

.include <bsd.port.mk>
