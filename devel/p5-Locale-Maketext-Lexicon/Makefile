# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Locale-Maketext-Lexicon
PORTVERSION=	0.96
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Locale/DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use other catalog formats in Locale::Maketext

LICENSE=	MIT

RUN_DEPENDS=	p5-Locale-Maketext>=1.17:${PORTSDIR}/devel/p5-Locale-Maketext

PERL_CONFIGURE=	yes

MAN1=		xgettext.pl.1
MAN3=		Locale::Maketext::Extract.3 \
		Locale::Maketext::Extract::Plugin::Base.3 \
		Locale::Maketext::Extract::Plugin::FormFu.3 \
		Locale::Maketext::Extract::Plugin::Generic.3 \
		Locale::Maketext::Extract::Plugin::Haml.3 \
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
