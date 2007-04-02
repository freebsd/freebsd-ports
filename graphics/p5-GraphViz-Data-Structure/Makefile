# ex:ts=8
# Ports collection makefile for:	p5-GraphViz-Data-Structure
# Date created:			Sep 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	GraphViz-Data-Structure
PORTVERSION=	0.15
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GraphViz
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Visualise data structures

BUILD_DEPENDS=	${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz \
		${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	GraphViz::Data::Structure.3

.include <bsd.port.mk>
