# Created by: jmz
# $FreeBSD$

PORTNAME=	PGPLOT
PORTVERSION=	2.21
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KGB
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 extension which makes available the pgplot library

BUILD_DEPENDS=	p5-ExtUtils-F77>=1.13:${PORTSDIR}/lang/p5-ExtUtils-F77
LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot

INSTALL_TARGET=	pure_install
SCRIPTS_ENV=	PERL=${PERL}
USE_FORTRAN=	yes
USES=		perl5

MAN3=		PGPLOT.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}

.if !defined(NOPORTEXAMPLES)
NO_STAGE=	yes
post-install:
	@${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} LICENSE test* ${EXAMPLESDIR}/
.endif

.if defined(MAINTAINER_MODE) && !defined(BATCH)
check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
	${_MAKE_JOBS} ${MAKE_ARGS} test
.endif

.include <bsd.port.mk>
