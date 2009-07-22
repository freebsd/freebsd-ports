# New ports collection makefile for:	devel/p5-SVN-Web
# Date created:				Feb 21 2004
# Whom:					CPANPLUS User <cpanplus@example.com>
#
# $FreeBSD$
#

PORTNAME=	SVN-Web
PORTVERSION=	0.53
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Subversion repository web frontend

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/RSS/Parser.pm:${PORTSDIR}/textproc/p5-XML-RSS-Parser \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate \
		p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Exception-Class>=1.22:${PORTSDIR}/devel/p5-Exception-Class \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Template-Plugin-Clickable-Email>=0:${PORTSDIR}/www/p5-Template-Plugin-Clickable-Email \
		p5-Template-Plugin-Clickable>=0:${PORTSDIR}/www/p5-Template-Plugin-Clickable \
		p5-Template-Plugin-Number-Format>=0:${PORTSDIR}/www/p5-Template-Plugin-Number-Format \
		p5-Template-Plugin-Subst>=0:${PORTSDIR}/www/p5-Template-Plugin-Subst \
		p5-Text-Diff-HTML>=0:${PORTSDIR}/textproc/p5-Text-Diff-HTML \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/Benchmark.pm:${PORTSDIR}/devel/p5-Test-Benchmark \
		${SITE_PERL}/Test/HTML/Tidy.pm:${PORTSDIR}/devel/p5-Test-HTML-Tidy \
		${SITE_PERL}/Test/WWW/Mechanize.pm:${PORTSDIR}/devel/p5-Test-WWW-Mechanize

PERL_MODBUILD=	yes
CONFIGURE_ARGS=	--skip_questions

MAN1=		svnweb-install.1 \
		svnweb-server.1
MAN3=		SVN::Web.3 \
		SVN::Web::Blame.3 \
		SVN::Web::Browse.3 \
		SVN::Web::Checkout.3 \
		SVN::Web::ConfigData.3 \
		SVN::Web::Diff.3 \
		SVN::Web::DiffParser.3 \
		SVN::Web::I18N.3 \
		SVN::Web::List.3 \
		SVN::Web::Log.3 \
		SVN::Web::RSS.3 \
		SVN::Web::Revision.3 \
		SVN::Web::Test.3 \
		SVN::Web::View.3 \
		SVN::Web::X.3 \
		SVN::Web::action.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/svnweb-install ${PREFIX}/bin
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
