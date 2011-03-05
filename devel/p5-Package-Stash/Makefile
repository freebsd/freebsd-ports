# New ports collection makefile for:	Package-Stash
# Date created:		8 June 2010
# Whom:		Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Package-Stash
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Routines for manipulating stashes

BUILD_DEPENDS=	\
	p5-Package-Stash-XS>=0.22:${PORTSDIR}/devel/p5-Package-Stash-XS \
	p5-Package-DeprecationManager>=0:${PORTSDIR}/devel/p5-Package-DeprecationManager
RUN_DEPENDS=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal	\
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	YES

MAN3=		Package::Stash.3 \
		Package::Stash::PP.3

.include <bsd.port.mk>
