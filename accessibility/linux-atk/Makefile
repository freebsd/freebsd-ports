# New ports collection makefile for:	linux-atk
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.9.1
CATEGORIES=	accessibility linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary

.if !defined(OVERRIDE_LINUX_BASE_PORT) || \
    (${OVERRIDE_LINUX_BASE_PORT} != "fc6" && \
    ${OVERRIDE_LINUX_BASE_PORT} != "f7" && \
    ${OVERRIDE_LINUX_BASE_PORT} != "f8")
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libglib-2.0.so.0:${PORTSDIR}/devel/linux-glib2
.endif

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST_SUB+=	LIBVERSION="901.0" PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
