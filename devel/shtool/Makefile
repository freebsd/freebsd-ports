# Created by: Ralf S. Engelschall
# $FreeBSD$

PORTNAME=	shtool
PORTVERSION=	2.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:GNU/} ${MASTER_SITE_OSSP:S/$/:OSSP/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:GNU tool/${PORTNAME}/:OSSP
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:GNU,OSSP

MAINTAINER=	vd@FreeBSD.org
COMMENT=	The GNU Portable Shell Tool

USES=		perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes

regression-test: test

test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
