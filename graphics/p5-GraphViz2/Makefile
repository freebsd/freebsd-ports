# New ports collection makefile for:	p5-GraphViz2
# Date created:		2011-07-21
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GraphViz2
PORTVERSION=	2.03
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSAVAGE
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A wrapper for AT&T Graphviz

BUILD_DEPENDS=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz \
		p5-Algorithm-Dependency>=1.110:${PORTSDIR}/devel/p5-Algorithm-Dependency \
		p5-Capture-Tiny>=0.10:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-ISA>=0.36:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Class-Load>=0.17:${PORTSDIR}/devel/p5-Class-Load \
		p5-DBI>=1.616:${PORTSDIR}/databases/p5-DBI \
		p5-Data-Section-Simple>=0.02:${PORTSDIR}/devel/p5-Data-Section-Simple \
		p5-File-Which>=1.09:${PORTSDIR}/sysutils/p5-File-Which \
		p5-HTML-Entities-Interpolate>=1.04:${PORTSDIR}/textproc/p5-HTML-Entities-Interpolate \
		p5-HTML-Tree>=4.2:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Hash-FieldHash>=0.10:${PORTSDIR}/devel/p5-Hash-FieldHash \
		p5-IPC-Run>=0.90:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Log-Handler>=0.71:${PORTSDIR}/devel/p5-Log-Handler \
		p5-Parse-RecDescent>=1.965.001:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Perl6-Slurp>=0.03:${PORTSDIR}/devel/p5-Perl6-Slurp \
		p5-Set-Array>=0.23:${PORTSDIR}/devel/p5-Set-Array \
		p5-Text-Xslate>=1.2000:${PORTSDIR}/textproc/p5-Text-Xslate \
		p5-TimeDate>=1.20:${PORTSDIR}/devel/p5-TimeDate \
		p5-Tree-DAG_Node>=1.06:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-Bare>=0.45:${PORTSDIR}/textproc/p5-XML-Bare \
		p5-XML-Tiny>=2.06:${PORTSDIR}/textproc/p5-XML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.44:${PORTSDIR}/devel/p5-Test-Pod

# This port also requires strict>=1.04 (5.10.0+), utf8>=1.09 (5.14.0+) and warnings>=1.12 (5.14.0+)
PERL_CONFIGURE=	5.14.0+

MAN3=		GraphViz2.3 \
		GraphViz2::DBI.3 \
		GraphViz2::Data::Grapher.3 \
		GraphViz2::Parse::ISA.3 \
		GraphViz2::Parse::Marpa.3 \
		GraphViz2::Parse::RecDescent.3 \
		GraphViz2::Parse::Regexp.3 \
		GraphViz2::Parse::STT.3 \
		GraphViz2::Parse::XML.3 \
		GraphViz2::Parse::Yacc.3 \
		GraphViz2::Parse::Yapp.3 \
		GraphViz2::Utils.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-File-Temp>=0.22:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS+=	p5-File-Temp>=0.22:${PORTSDIR}/devel/p5-File-Temp
.endif

.if ${PERL_LEVEL} < 501200
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-HTTP-Tiny>=0.012:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-PathTools>=3.3300:${PORTSDIR}/devel/p5-PathTools \
		p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-parent>=0.225:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-HTTP-Tiny>=0.012:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-PathTools>=3.3300:${PORTSDIR}/devel/p5-PathTools \
		p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-parent>=0.225:${PORTSDIR}/devel/p5-parent
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
