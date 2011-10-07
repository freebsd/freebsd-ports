# New ports collection makefile for:	databases/p5-GraphViz-DBI
# Date created:				10 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	GraphViz-DBI
PORTVERSION=	1.100860
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARCEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GraphViz::DBI - graph database tables and relations

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz

PERL_CONFIGURE=	yes

MAN3=		GraphViz::DBI.3

.include <bsd.port.mk>
