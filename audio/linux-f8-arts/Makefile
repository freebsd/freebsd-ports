# New ports collection makefile for:	linux-arts
# Date created:				6 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		arts
PORTVERSION=		1.0.3
PORTREVISION=		3
CATEGORIES=		audio kde linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	8.0/en/os/${MACHINE_ARCH}/RedHat/RPMS
PKGNAMEPREFIX=		linux-
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.1$/-1/}-1.${MACHINE_ARCH}
EXTRACT_SUFX=		.rpm
EXTRACT_ONLY=

MAINTAINER=		bms@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

USE_LINUX=		yes
USE_LINUX_PREFIX=	yes
LDCONFIG_LINUX=		${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		rpm
NO_BUILD=		yes
PLIST=			${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
			--nodeps --replacepkgs
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

do-install:
	@${LOCALBASE}/bin/rpm -U ${RPMFLAGS} ${RPMDIR}/${DISTFILES}
	@${LDCONFIG_LINUX}

.include <bsd.port.mk>
