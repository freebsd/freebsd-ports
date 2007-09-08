# New ports collection makefile for:	p5-Tie-Hash-Regex
# Date created:				01 Jan 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-Hash-Regex
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Match hash keys using Regular Expressions

BUILD_DEPENDS=	p5-Attribute-Handlers>=0.76:${PORTSDIR}/devel/p5-Attribute-Handlers
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Tie::Hash::Regex.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
