# New ports collection makefile for:	graphics/p5-GraphViz
# Date created:				09 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	GraphViz
PORTVERSION=	1.5
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GraphViz
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Graph.pm:${PORTSDIR}/math/p5-Graph \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Math/Bezier.pm:${PORTSDIR}/math/p5-Math-Bezier
RUN_DEPENDS=	${BUILD_DEPENDS} \
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

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
