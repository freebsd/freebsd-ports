# New ports collection makefile for:	Devel-Cover
# Date created:	   10 October 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Devel-Cover
PORTVERSION=	0.93
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Code coverage metrics for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PPI-HTML>=1.07:${PORTSDIR}/textproc/p5-PPI-HTML \
		p5-Parallel-Iterator>=0:${PORTSDIR}/devel/p5-Parallel-Iterator \
		p5-Pod-Coverage>=0.06:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Template-Toolkit>=2:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

OPTIONS_DEFINE=	DOCS

PERL_CONFIGURE=	yes

MAN1=		cover.1 cpancover.1 gcov2perl.1
MAN3=		Devel::Cover.3 \
		Devel::Cover::Annotation::Git.3 \
		Devel::Cover::Annotation::Random.3 \
		Devel::Cover::Annotation::Svk.3 \
		Devel::Cover::Branch.3 \
		Devel::Cover::Condition.3 \
		Devel::Cover::Condition_and_2.3 \
		Devel::Cover::Condition_and_3.3 \
		Devel::Cover::Condition_or_2.3 \
		Devel::Cover::Condition_or_3.3 \
		Devel::Cover::Condition_xor_4.3 \
		Devel::Cover::Criterion.3 \
		Devel::Cover::DB.3 \
		Devel::Cover::DB::Digests.3 \
		Devel::Cover::DB::File.3 \
		Devel::Cover::DB::IO.3 \
		Devel::Cover::DB::IO::JSON.3 \
		Devel::Cover::DB::IO::Storable.3 \
		Devel::Cover::DB::Structure.3 \
		Devel::Cover::Dumper.3 \
		Devel::Cover::Html_Common.3 \
		Devel::Cover::Op.3 \
		Devel::Cover::Pod.3 \
		Devel::Cover::Report::Compilation.3 \
		Devel::Cover::Report::Html.3 \
		Devel::Cover::Report::Html_basic.3 \
		Devel::Cover::Report::Html_minimal.3 \
		Devel::Cover::Report::Html_subtle.3 \
		Devel::Cover::Report::Sort.3 \
		Devel::Cover::Report::Text.3 \
		Devel::Cover::Report::Text2.3 \
		Devel::Cover::Report::Vim.3 \
		Devel::Cover::Statement.3 \
		Devel::Cover::Subroutine.3 \
		Devel::Cover::Test.3 \
		Devel::Cover::Time.3 \
		Devel::Cover::Truth_Table.3 \
		Devel::Cover::Tutorial.3 \
		Devel::Cover::Web.3
PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

# Regarding JSON format, Devel::Cover will try JSON and JSON:PP.
# Thus, users of Perl 5.14 and above use JSON:PP (core module).
.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS+=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON
.endif

.include <bsd.port.post.mk>
