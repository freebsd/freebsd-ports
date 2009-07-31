# New ports collection makefile for:	databases/p5-GraphViz-DBI
# Date created:				10 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	GraphViz-DBI
PORTVERSION=	0.02
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	GraphViz::DBI - graph database tables and relations

BUILD_DEPENDS=	${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		GraphViz::DBI.3

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/DBI.pm

.include <bsd.port.mk>
