# New ports collection makefile for:	devel/p5-Check-ISA
# Date created:				2008/09/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Check-ISA
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/N/NU/NUFFIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DWIM, correct checking of an object's class

RUN_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Check::ISA.3

.include <bsd.port.mk>
