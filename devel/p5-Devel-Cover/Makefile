# New ports collection makefile for:	Devel-Cover
# Date created:	   10 October 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Devel-Cover
PORTVERSION=	0.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Code coverage metrics for Perl

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Pod-Coverage
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/Differences.pm:${PORTSDIR}/devel/p5-Test-Differences

PERL_CONFIGURE=	yes

MAN1=		cover.1 cpancover.1 gcov2perl.1
MAN3=		Devel::Cover.3 \
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
		Devel::Cover::DB::File.3 \
		Devel::Cover::DB::Structure.3 \
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
		Devel::Cover::Statement.3 \
		Devel::Cover::Subroutine.3 \
		Devel::Cover::Time.3 \
		Devel::Cover::Truth_Table.3 \
		Devel::Cover::Tutorial.3

.if !defined(NOPORTDOCS)
PORTDOCS=	BUGS CHANGES README TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
