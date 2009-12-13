# New ports collection makefile for:  IO-Interactive
# Date created: 12 December 2009
# Whom:		Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	IO-Interactive
PORTVERSION=	0.0.6
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Utilities for interactive I/O

BUILD_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=	IO::Interactive.3

.include <bsd.port.mk>
