# Created by: Jerry Hicks <wghicks@bellsouth.net>
# $FreeBSD$

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

USES=		perl5
USE_PERL5=	configure

MAN3=		Parse::RecDescent.3

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${DOCSDIR}/tutorial
.endif

.include <bsd.port.mk>
