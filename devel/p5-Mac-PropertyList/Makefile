# New ports collection makefile for:	p5-Mac-PropertyList
# Date created:	24 December 2010
# Whom:		Nobutaka Mantani <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mac-PropertyList
PORTVERSION=	1.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A Perl extension for parsing Mac OS X property lists

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

BUILD_DEPENDS=	${SITE_PERL}/XML/Entities.pm:${PORTSDIR}/textproc/p5-XML-Entities
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PropertyList.3 \
	ReadBinary.3

.include <bsd.port.mk>
