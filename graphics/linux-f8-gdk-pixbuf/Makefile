# New ports collection makefile for:	linux-gdk-pixbuf
# Date created:		23 December 2003
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0.11.3.5
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=fedora/fedora/${BASEVERSION}/${MACHINE_ARCH}/RPMS.updates
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^([^\.]+\.[^\.]+\.[^\.]+)\./\1-/}.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Linux version of the graphic library for GTK+

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=	linux-gtk2*

USE_LINUX_PREFIX=yes
USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386
DIST_SUBDIR=	rpm
NO_BUILD=	yes
PLIST_SUB=	VERSION=${PORTVERSION:C/^([^\.]+\.[^\.]+\.[^\.]+).+/\1/}

# Set the version of Fedora Core
BASEVERSION?=	2
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath /var/lib/rpm\
		--nodeps --replacepkgs

do-install:
	@for rpm in ${DISTFILES}; do\
		${ECHO_MSG} $$rpm;\
		rpm -U ${RPMFLAGS} ${DISTDIR}/${DIST_SUBDIR}/$$rpm || true;\
	done

.include <bsd.port.mk>
