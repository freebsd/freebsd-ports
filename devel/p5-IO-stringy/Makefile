# New ports collection makefile for:	p5-IO-stringy
# Date created:				April 27 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-stringy
PORTVERSION=	1.212
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	eivind@FreeBSD.org

USE_PERL5=	YES

MAN3=		IO::AtomicFile.3 IO::InnerFile.3 IO::Lines.3 IO::Scalar.3 \
		IO::ScalarArray.3 IO::Stringy.3 \
		IO::Wrap.3 IO::WrapTie.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
