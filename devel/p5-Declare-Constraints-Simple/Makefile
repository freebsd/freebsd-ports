# New ports collection makefile for:	p5-Declare-Constraints-Simple
# Date created:		2010-12-03
# Whom:			Anes Muhametov <anes@anes.su>
#
# $FreeBSD$
#

PORTNAME=	Declare-Constraints-Simple
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PHAYLON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative Validation of Perl Data Structures

BUILD_DEPENDS=	p5-Class-Inspector>=1.24:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	p5-Class-Inspector>=1.24:${PORTSDIR}/devel/p5-Class-Inspector
TEST_DEPENDS=	p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased

PERL_CONFIGURE=	yes

MAN3=	Declare::Constraints::Simple::Library::Scalar.3 \
	Declare::Constraints::Simple::Library::Operators.3 \
	Declare::Constraints::Simple::Library::Array.3 \
	Declare::Constraints::Simple::Library.3 \
	Declare::Constraints::Simple::Library::Exportable.3 \
	Declare::Constraints::Simple::Library::Referencial.3 \
	Declare::Constraints::Simple::Result.3 \
	Declare::Constraints::Simple.3 \
	Declare::Constraints::Simple::Library::OO.3 \
	Declare::Constraints::Simple::Library::Numerical.3 \
	Declare::Constraints::Simple::Library::Hash.3 \
	Declare::Constraints::Simple::Library::Base.3 \
	Declare::Constraints::Simple::Library::General.3

.include <bsd.port.mk>
