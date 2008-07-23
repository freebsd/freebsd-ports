# New ports collection makefile for:	devel/p5-Mouse
# Date created:				23 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mouse
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/S/SA/SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Moose minus the antlers

RUN_DEPENDS=	\
	p5-Sub-Exporter>=0.972:${PORTSDIR}/devel/p5-Sub-Exporter \
	p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
	p5-Class-Method-Modifiers>=1.01:${PORTSDIR}/devel/p5-Class-Method-Modifiers
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Mouse.3 \
	Mouse::Meta::Attribute.3 \
	Mouse::Meta::Class.3 \
	Mouse::Object.3 \
	Mouse::Role.3 \
	Mouse::TypeRegistry.3 \
	Squirrel.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
