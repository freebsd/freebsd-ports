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
COMMENT=	Recursive descent parsing framework for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${STAGEDIR}${DOCSDIR}/tutorial
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.62:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>
