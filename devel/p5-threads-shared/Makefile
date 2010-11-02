# New ports collection makefile for:	p5-threads-shared
# Date created:		2007-03-18
# Whom:			Ruben van Staveren
#
# $FreeBSD$
#

PORTNAME=	threads-shared
PORTVERSION=	1.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/J/JD/JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ruben@verweg.com
COMMENT=	Perl extension for sharing data structures between threads

BUILD_DEPENDS=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads
RUN_DEPENDS=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads

PERL_CONFIGURE=	5.8.0+

MAN3=		threads::shared.3

.include <bsd.port.mk>
