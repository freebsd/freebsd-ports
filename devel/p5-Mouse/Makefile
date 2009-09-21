# New ports collection makefile for:	devel/p5-Mouse
# Date created:				23 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mouse
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/G/GF/GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose minus the antlers

PERL_CONFIGURE=	5.8.5+

MAN3=	Mouse.3 \
	Mouse::Meta::Attribute.3 \
	Mouse::Meta::Class.3 \
	Mouse::Meta::Module.3 \
	Mouse::Meta::TypeConstraint.3 \
	Mouse::Object.3 \
	Mouse::Role.3 \
	Mouse::Util.3 \
	Mouse::Util::TypeConstraints.3 \
	Squirrel.3 \
	Test::Mouse.3 \
	ouse.3

post-install:
	@${CAT} ${PKGDIR}/pkg-message

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
