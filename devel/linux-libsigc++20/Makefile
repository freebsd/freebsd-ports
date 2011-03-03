# New ports collection makefile for:	devel/linux-libsigc++20
# Date created:				28 Jun 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		libsigc
PORTVERSION=		2.0.17
PORTREVISION=		2
CATEGORIES=		devel linux
MASTER_SITES=		CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=		${PORTNAME}++20-${PORTVERSION}-${RPMVERSION}

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Callback Framework for C++ (linux version)

CONFLICTS=		linux-f8-libsigc++20-[0-9]* linux-f10-libsigc++20-[0-9]*

ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX_RPM=		yes
RPMVERSION=		1
LINUX_DIST_VER=		4
USE_LDCONFIG=		yes
MASTER_SITE_SRC_SUBDIR=	../extras/${LINUX_DIST_VER}/SRPMS

.if defined(NOPORTDOCS)
REMOVE_DIRS=	usr/share
.endif

pre-install:
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done

.include <bsd.port.mk>
