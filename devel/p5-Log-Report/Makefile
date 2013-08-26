# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Log-Report
PORTVERSION=	0.99.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Report a problem, pluggable handlers and language support

RUN_DEPENDS=	p5-Devel-GlobalDestruction>=0.09:${PORTSDIR}/devel/p5-Devel-GlobalDestruction

USES=		perl5
USE_PERL5=	configure

MAN3=	Log::Report.3 \
	Log::Report::Die.3 \
	Log::Report::Dispatcher.3 \
	Log::Report::Dispatcher::Callback.3 \
	Log::Report::Dispatcher::File.3 \
	Log::Report::Dispatcher::Log4perl.3 \
	Log::Report::Dispatcher::LogDispatch.3 \
	Log::Report::Dispatcher::Perl.3 \
	Log::Report::Dispatcher::Syslog.3 \
	Log::Report::Dispatcher::Try.3 \
	Log::Report::Exception.3 \
	Log::Report::Extract.3 \
	Log::Report::Extract::PerlPPI.3 \
	Log::Report::Extract::Template.3 \
	Log::Report::Lexicon::Index.3 \
	Log::Report::Lexicon::MOTcompact.3 \
	Log::Report::Lexicon::PO.3 \
	Log::Report::Lexicon::POT.3 \
	Log::Report::Lexicon::POTcompact.3 \
	Log::Report::Lexicon::Table.3 \
	Log::Report::Message.3 \
	Log::Report::Translator.3 \
	Log::Report::Translator::Gettext.3 \
	Log::Report::Translator::POT.3 \
	Log::Report::Util.3 \
	Log::Report::Win32Locale.3

.include <bsd.port.mk>
