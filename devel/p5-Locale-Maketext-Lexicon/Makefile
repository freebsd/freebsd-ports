# New ports collection makefile for:	p5-Locale-Maketext-Lexicon
# Date created:				February 23, 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext-Lexicon
PORTVERSION=	0.86
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Locale/DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use other catalog formats in Locale::Maketext

BUILD_DEPENDS=	p5-Locale-Maketext>=1.17:${PORTSDIR}/devel/p5-Locale-Maketext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		xgettext.pl.1
MAN3=		Locale::Maketext::Extract.3 \
		Locale::Maketext::Extract::Plugin::Base.3 \
		Locale::Maketext::Extract::Plugin::FormFu.3 \
		Locale::Maketext::Extract::Plugin::Generic.3 \
		Locale::Maketext::Extract::Plugin::Mason.3 \
		Locale::Maketext::Extract::Plugin::PPI.3 \
		Locale::Maketext::Extract::Plugin::Perl.3 \
		Locale::Maketext::Extract::Plugin::TT2.3 \
		Locale::Maketext::Extract::Plugin::TextTemplate.3 \
		Locale::Maketext::Extract::Plugin::YAML.3 \
		Locale::Maketext::Extract::Run.3 \
		Locale::Maketext::Lexicon.3 \
		Locale::Maketext::Lexicon::Auto.3 \
		Locale::Maketext::Lexicon::Gettext.3 \
		Locale::Maketext::Lexicon::Msgcat.3 \
		Locale::Maketext::Lexicon::Tie.3

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
