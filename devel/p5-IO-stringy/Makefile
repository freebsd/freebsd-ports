# New ports collection makefile for:	p5-IO-stringy
# Date created:				April 27 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-stringy
PORTVERSION=	1.220
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	ijliao@FreeBSD.org

PERL_CONFIGURE=	YES

MAN3=		IO::AtomicFile.3 IO::InnerFile.3 IO::Lines.3 IO::Scalar.3 \
		IO::ScalarArray.3 IO::Stringy.3 \
		IO::Wrap.3 IO::WrapTie.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
