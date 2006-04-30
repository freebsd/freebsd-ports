# New ports collection makefile for:	devel/p5-Class-MOP
# Date created:				14 Apr 2006
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Class-MOP
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	A Meta Object Protocol for Perl 5

BUILD_DEPENDS=	${RUN_DEPENDS} \
	p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	\
	p5-Scalar-List-Utils>=1.18:${PORTSDIR}/lang/p5-Scalar-List-Utils \
	p5-Sub-Name>=0.02:${PORTSDIR}/devel/p5-Sub-Name

PERL_MODBUILD=	yes

MAN3=	Class::MOP.3 \
	Class::MOP::Attribute.3 \
	Class::MOP::Class.3 \
	Class::MOP::Method.3 \
	metaclass.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
