# New ports collection makefile for:	graphics/p5-GraphViz
# Date created:				09 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	GraphViz
PORTVERSION=	2.04
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	GraphViz - Perl interface to the GraphViz graphing tool

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		dot:${PORTSDIR}/graphics/graphviz

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
