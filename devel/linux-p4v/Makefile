# New ports collection makefile for:	linux-arts
# Date created:				6 October 2003
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		p4v
PORTVERSION=		2003.1
PORTREVISION=		48708
CATEGORIES=		devel linux
MASTER_SITES=		http://www.perforce.com/downloads/perforce/r03.1/bin.linux72x86/
PKGNAMEPREFIX=		linux-
DISTNAME=		${PORTNAME}-${PORTVERSION}-${PORTREVISION}.${MACHINE_ARCH}
EXTRACT_SUFX=		.rpm
EXTRACT_ONLY=

MAINTAINER=		bms@FreeBSD.org
COMMENT=		Visual client for Perforce SCM

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

NO_CDROM=		yes
RESTRICTED=		"Binary redistribution restrictions in effect"

BROKEN=			"Incorrect distinfo"

USE_LINUX_PREFIX=	yes
LDCONFIG_LINUX=		${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		rpm
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
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
