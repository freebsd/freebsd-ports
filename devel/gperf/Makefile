# $FreeBSD$

PORTNAME=	gperf
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gperf

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords

LICENSE=	GPLv2

CONFLICTS=	ace+tao-[0-9]*
MAKE_JOBS_UNSAFE=	yes
# avoid GPL3
PORTSCOUT=	skipv:3.0.4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INFO=		gperf

regression-test: test

test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
