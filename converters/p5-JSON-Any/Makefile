# New ports collection makefile for:	JSON-Any
# Date created:		7 Apr 2007
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	JSON-Any
PORTVERSION=	1.29
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Wrapper Class for the various JSON classes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2.02:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS=	p5-JSON>=2.02:${PORTSDIR}/converters/p5-JSON

PERL_CONFIGURE=	yes

MAN3=		JSON::Any.3

.include <bsd.port.mk>
