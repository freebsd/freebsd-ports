# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

COMMENT=	Wine built with the Staging patchset

SLAVE_PORT=	wine-devel

CONFLICTS_INSTALL=	wine-[0-9]* wine-devel-[0-9]* i386-wine-[0-9]* \
			i386-wine-staging-[0-9]* i386-wine-devel-[0-9]*

OPTIONS_SET=	LIBXSLT MPG123 HAL STAGING V4L X11

MASTERDIR=	${.CURDIR}/../wine-devel
PLIST=		${MASTERDIR}/pkg-plist
USE_AUTOTOOLS=	autoconf:env

.include "${MASTERDIR}/Makefile"

PKGNAMESUFFIX=	-staging
