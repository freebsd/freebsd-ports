# New ports collection makefile for:   linux-vsound
# Date created:        28 January 2001
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-vsound
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	audio linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kris
DISTNAME=	vsound-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Utility for capturing audio streams from Linux binaries

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox/

USE_LINUX=	yes
NO_BUILD=	yes

do-install:
	@cd ${PREFIX} && ${TAR} xfz ${DISTDIR}/${DISTFILES}

.include <bsd.port.mk>
