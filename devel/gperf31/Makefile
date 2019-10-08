# $FreeBSD$

PORTNAME=	gperf
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	31

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Generates perfect hash functions for sets of keywords

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	ace+tao-[0-9]*
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INFO=		gperf31
TEST_TARGET=	check

post-install:
	${MV} ${STAGEDIR}/${PREFIX}/bin/gperf \
		${STAGEDIR}/${PREFIX}/bin/gperf31
	${MV} ${STAGEDIR}/${PREFIX}/man/man1/gperf.1 \
		${STAGEDIR}/${PREFIX}/man/man1/gperf31.1
	${MV} ${STAGEDIR}/${DOCSDIR}/gperf.html \
		${STAGEDIR}/${DOCSDIR}/gperf31.html
	${MV} ${STAGEDIR}/${PREFIX}/${INFO_PATH}/gperf.info \
		${STAGEDIR}/${PREFIX}/${INFO_PATH}/gperf31.info

.include <bsd.port.mk>
