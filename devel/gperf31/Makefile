# $FreeBSD$

PORTNAME=	gperf
PORTVERSION=	3.1
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	31

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	ace+tao-[0-9]* gperf-*
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INFO=		gperf
TEST_TARGET=	check

.include <bsd.port.mk>
