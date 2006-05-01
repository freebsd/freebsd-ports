# New ports collection makefile for:	linux-atk
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	accessibility linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
PLIST_SUB+=	LIBVERSION="800.0" PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
