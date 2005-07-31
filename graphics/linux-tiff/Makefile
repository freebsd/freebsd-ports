# New ports collection makefile for: linux-tiff
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.6.1
PORTREVISION=	3
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_SUSE}
MASTER_SITE_SUBDIR=	i386/update/9.2/rpm/i586
PKGNAMEPREFIX=	linux-
DISTNAME=	libtiff-3.6.1-47.6.i586.rpm
EXTRACT_ONLY=
EXTRACT_SUFX=

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

DIST_SUBDIR=	rpm/i386/suse/9.2
DOCDIRS=	usr/share/doc/libtiff-3.6.1
ONLY_FOR_ARCHS=	amd64 i386
PLIST=		${WRKDIR}/plist
PLIST_DIRS=	usr/share/doc/packages/libtiff usr/share/doc/packages
PLIST_FILES=	usr/lib/libtiff.so.3 usr/lib/libtiff.so.3.6.1 \
		usr/share/doc/packages/libtiff/COPYRIGHT \
		usr/share/doc/packages/libtiff/README
USE_LINUX=	yes
USE_LINUX_PREFIX=yes

# dummy target so rpm can be in BUILD_DEPENDS
do-build:
	@${DO_NADA}

do-install:
	${MKDIR} ${WRKSRC}
	@rpm -U --ignorearch --ignoreos --root ${PREFIX} --dbpath /var/lib/rpm \
		--nodeps --replacepkgs --noscripts ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		|| ${TRUE}

post-install:
	@chroot ${LINUXBASE} sbin/ldconfig

.include <bsd.port.mk>
