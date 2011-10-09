# New ports collection makefile for:	p5-Class-Load
# Date created:		2009-10-16
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Load
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	A working (require Class::Name) and more

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-OptList>0:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Package-Stash>=0.32:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Module-Runtime>=0.009:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=	Class::Load.3

.include <bsd.port.mk>
