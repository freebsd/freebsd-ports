# New ports collection makefile for:	graphics/p5-GraphViz
# Date created:				09 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	GraphViz
PORTVERSION=	2.02
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GraphViz
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	GraphViz - Perl interface to the GraphViz graphing tool

BUILD_DEPENDS=	${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::GraphVizProf.3 \
		GraphViz.3 \
		GraphViz::Data::Grapher.3 \
		GraphViz::No.3 \
		GraphViz::Parse::RecDescent.3 \
		GraphViz::Parse::Yacc.3 \
		GraphViz::Parse::Yapp.3 \
		GraphViz::Regex.3 \
		GraphViz::Small.3 \
		GraphViz::XML.3

.include <bsd.port.mk>
