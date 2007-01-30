# New ports collection makefile for:	linux libperl
# Date created:			Sun Dec 11 16:38:34 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# Based on:		emulators/linux_base by marcel@FreeBSD.org and
#			devel/linux-sdl12 by freebsd-emulation@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libperl
PORTVERSION=	5.8.5
CATEGORIES=	lang linux
MASTER_SITES=	ftp://195.220.108.108/linux/conectiva/snapshot/i386/RPMS.extra/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}${PORTVERSION:R}-${PORTVERSION}-67091cl.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for embedding the perl interpreter (linux version)

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

USE_LINUX=	yes
USE_LINUX_PREFIX=	yes
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
NO_BUILD=	yes
PLIST=		${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MACHINE_ARCH=	i386
.endif

do-install:
	@${LOCALBASE}/bin/rpm -U ${RPMFLAGS} ${RPMDIR}/${DISTFILES}
	@${LDCONFIG_LINUX}

.include <bsd.port.post.mk>
