# New ports collection makefile for:    unshield
# Date created:         08 April 2004
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	unshield
PORTVERSION=	0.5
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=synce

MAINTAINER=	se@FreeBSD.org
COMMENT=	Extract data from InstallShield CAB files

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--program-prefix=""

.include <bsd.port.mk>
