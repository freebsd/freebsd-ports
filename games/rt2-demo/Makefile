# New ports collection makefile for: rt2 demo
# Date created:		Sun Jun 18 11:23:18 CEST 2000
# Whom:			se@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	rt2_demo
PORTVERSION=	1.54b
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/rt2/
DISTNAME=	rt2-demo
EXTRACT_SUFX=	.run
EXTRACT_ONLY=

MAINTAINER=	se@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
		@${SH} ${FILESDIR}/do-install ${PREFIX} ${DISTDIR}

.include <bsd.port.mk>
