# Created by: tobez
# $FreeBSD$

PORTNAME=	GraphViz-DBI
PORTVERSION=	1.100860
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARCEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GraphViz::DBI - graph database tables and relations

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-GraphViz>=0:graphics/p5-GraphViz
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-GraphViz>=0:graphics/p5-GraphViz

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
