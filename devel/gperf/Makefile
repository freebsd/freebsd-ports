# New ports collection makefile for:    gperf
# Date created:         19.04.1999
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gperf
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gperf

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords

GNU_CONFIGURE=	yes
MAN1=		gperf.1
INFO=		gperf
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

post-install:
		install-info ${PREFIX}/info/gperf.info ${PREFIX}/info/dir

.include <bsd.port.mk>
