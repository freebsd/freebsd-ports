# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	Module-CoreList
PORTVERSION=	2.96
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	See what modules shipped with versions of Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=		Module::CoreList.3 Module::CoreList::Utils.3

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
