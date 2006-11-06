# New ports collection makefile for: linux-esound
# Date created:		01/09/18
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esound
CATEGORIES=	audio linux
PORTVERSION=	0.2.36
DISTNAME=	${PORTNAME}-${PORTVERSION}-0.fc4.1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	RPM of esound

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libaudiofile.so.0:${PORTSDIR}/audio/linux-libaudiofile

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	ESOUND_VERSION="${PORTVERSION}"

.include <bsd.port.mk>
