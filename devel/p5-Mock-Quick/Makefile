# New ports collection makefile for:	p5-Mock-Quick
# Date Created:				17 Feb, 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mock-Quick
PORTVERSION=	1.102
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Quickly mock objects and classes

RUN_DEPENDS=	p5-Exporter-Declare>=0:${PORTSDIR}/devel/p5-Exporter-Declare
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Mock::Quick.3 Object::Quick.3 \
		Mock::Quick::Class.3 \
		Mock::Quick::Method.3 \
		Mock::Quick::Object.3 \
		Mock::Quick::Object::Control.3 \
		Mock::Quick::Util.3

.include <bsd.port.mk>
