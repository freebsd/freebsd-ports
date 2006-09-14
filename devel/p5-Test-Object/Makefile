# New ports collection makefile for:	devel/p5-Test-Object
# Date created:				05 September 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Object
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Thoroughly testing objects via registered handlers

RUN_DEPENDS=	p5-Scalar-List-Utils>=1.16:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-Simple>=0.63:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Object.3

.include <bsd.port.mk>
