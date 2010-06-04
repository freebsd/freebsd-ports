# New ports collection makefile for:    gperf
# Date created:         19.04.1999
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gperf
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gperf

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords

LICENSE=	GPLv2
CONFLICTS=	ace+tao-[0-9]*

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

MAN1=		gperf.1
INFO=		gperf

# avoid GPL3
PORTSCOUT=	skipv:3.0.4

regression-test: test

test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
