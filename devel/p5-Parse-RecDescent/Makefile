# New ports collection makefile for:	p5-Parse-RecDescent
# Date created:				July 9th 1999
# Whom:	      				Jerry Hicks <wghicks@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	Parse-RecDescent
PORTVERSION=	1.967.009
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A recursive descent parsing framework for Perl

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.62:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker

TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	YES

MAN3=		Parse::RecDescent.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${DOCSDIR}/tutorial
.endif

.include <bsd.port.mk>
