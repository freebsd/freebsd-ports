# New ports collection makefile for:	p5-IO-stringy
# Version required:			1.203
# Date created:				April 27 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	IO-stringy-1.203
PKGNAME=	p5-IO-stringy-1.203
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO

MAINTAINER=	eivind@FreeBSD.org

USE_PERL5=	YES

MAN3=		IO::AtomicFile.3 IO::Lines.3 IO::Scalar.3 \
		IO::ScalarArray.3 IO::Stringy.3 \
		IO::Wrap.3 IO::WrapTie.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
