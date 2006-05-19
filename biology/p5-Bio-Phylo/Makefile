# New ports collection makefile for:	Bio-Phylo
# Date created:				12 Mar 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bio-Phylo
PORTVERSION=	0.12
CATEGORIES=	biology perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Bio
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Phylogenetic analysis using perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Math/Random.pm:${PORTSDIR}/math/p5-Math-Random \
		${SITE_PERL}/SVG.pm:${PORTSDIR}/textproc/p5-SVG \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Bio::Phylo.3 \
	Bio::Phylo::Forest.3 \
	Bio::Phylo::Forest::Node.3 \
	Bio::Phylo::Forest::Tree.3 \
	Bio::Phylo::Generator.3 \
	Bio::Phylo::IO.3 \
	Bio::Phylo::Listable.3 \
	Bio::Phylo::Manual.3 \
	Bio::Phylo::Matrices.3 \
	Bio::Phylo::Matrices::Alignment.3 \
	Bio::Phylo::Matrices::Datum.3 \
	Bio::Phylo::Matrices::Matrix.3 \
	Bio::Phylo::Matrices::Sequence.3 \
	Bio::Phylo::Parsers::Fastnewick.3 \
	Bio::Phylo::Parsers::Fastnexus.3 \
	Bio::Phylo::Parsers::Newick.3 \
	Bio::Phylo::Parsers::Nexus.3 \
	Bio::Phylo::Parsers::Table.3 \
	Bio::Phylo::Parsers::Taxlist.3 \
	Bio::Phylo::Taxa.3 \
	Bio::Phylo::Taxa::Taxon.3 \
	Bio::Phylo::Treedrawer.3 \
	Bio::Phylo::Treedrawer::Svg.3 \
	Bio::Phylo::Unparsers::Mrp.3 \
	Bio::Phylo::Unparsers::Newick.3 \
	Bio::Phylo::Unparsers::Nexus.3 \
	Bio::Phylo::Unparsers::Pagel.3 \
	Bio::Phylo::Util::CONSTANT.3 \
	Bio::Phylo::Util::Exceptions.3 \
	Bio::Phylo::Util::IDPool.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
