# New ports collection makefile for:	linux-allegro
# Date created:				18 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	devel linux
MASTER_SITES=	http://membres.lycos.fr/ebotcazou/allegro/
PKGNAMEPREFIX=	linux-

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Cross-platform game programming library (linux version)

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=

USE_LINUX=		yes
USE_LINUX_PREFIX=	yes
ONLY_FOR_ARCHS=		i386

RPM_SET=	${PORTNAME}-${PORTVERSION}-1.${ARCH}.rpm
PLIST=		${MASTERDIR}/pkg-plist
MD5_FILE=	${MASTERDIR}/distinfo

.include "../../x11-toolkits/linux-gtk/Makefile"
