# New ports collection makefile for:	linux-par2cmdline
# Date created:				25 April 2007
# Whom:					ganael.laplanche@martymac.org
#
# $FreeBSD$
#

PORTNAME=	par2cmdline
PORTVERSION=	0.4
CATEGORIES=	archivers linux
MASTER_SITE_SUBDIR=	../extras/${LINUX_DIST_VER}/${LINUX_RPM_ARCH} ../extras/${LINUX_DIST_VER}/SRPMS
DISTNAME=	${PORTNAME}-${PORTVERSION}-10.fc4

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Linux version of par2cmdline

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4

PLIST_FILES=	usr/bin/par \
		usr/bin/par2 \
		usr/bin/par2verify \
		usr/bin/par2repair \
		usr/bin/par2create
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog README

.include <bsd.port.mk>
