# New ports collection makefile for:	p5-Log-Log4perl
# Date created:				Sat Oct 19 11:22:09 CEST 2002
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Log-Log4perl
PORTVERSION=	1.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Log4j implementation for Perl

RUN_DEPENDS+=	p5-Storable>0:${PORTSDIR}/devel/p5-Storable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		l4p-tmpl.1
MAN3=		Log::Log4perl.3 \
		Log::Log4perl::Appender.3 \
		Log::Log4perl::Appender::Buffer.3 \
		Log::Log4perl::Appender::DBI.3 \
		Log::Log4perl::Appender::File.3 \
		Log::Log4perl::Appender::Limit.3 \
		Log::Log4perl::Appender::RRDs.3 \
		Log::Log4perl::Appender::Screen.3 \
		Log::Log4perl::Appender::ScreenColoredLevels.3 \
		Log::Log4perl::Appender::Socket.3 \
		Log::Log4perl::Appender::String.3 \
		Log::Log4perl::Appender::Synchronized.3 \
		Log::Log4perl::Appender::TestArrayBuffer.3 \
		Log::Log4perl::Appender::TestBuffer.3 \
		Log::Log4perl::Appender::TestFileCreeper.3 \
		Log::Log4perl::Catalyst.3 \
		Log::Log4perl::Config.3 \
		Log::Log4perl::Config::BaseConfigurator.3 \
		Log::Log4perl::Config::DOMConfigurator.3 \
		Log::Log4perl::Config::PropertyConfigurator.3 \
		Log::Log4perl::Config::Watch.3 \
		Log::Log4perl::DateFormat.3 \
		Log::Log4perl::FAQ.3 \
		Log::Log4perl::Filter.3 \
		Log::Log4perl::Filter::Boolean.3 \
		Log::Log4perl::Filter::LevelMatch.3 \
		Log::Log4perl::Filter::LevelRange.3 \
		Log::Log4perl::Filter::StringMatch.3 \
		Log::Log4perl::InternalDebug.3 \
		Log::Log4perl::JavaMap.3 \
		Log::Log4perl::JavaMap::ConsoleAppender.3 \
		Log::Log4perl::JavaMap::FileAppender.3 \
		Log::Log4perl::JavaMap::JDBCAppender.3 \
		Log::Log4perl::JavaMap::NTEventLogAppender.3 \
		Log::Log4perl::JavaMap::RollingFileAppender.3 \
		Log::Log4perl::JavaMap::SyslogAppender.3 \
		Log::Log4perl::JavaMap::TestBuffer.3 \
		Log::Log4perl::Layout.3 \
		Log::Log4perl::Layout::NoopLayout.3 \
		Log::Log4perl::Layout::PatternLayout.3 \
		Log::Log4perl::Layout::PatternLayout::Multiline.3 \
		Log::Log4perl::Layout::SimpleLayout.3 \
		Log::Log4perl::Level.3 \
		Log::Log4perl::Logger.3 \
		Log::Log4perl::MDC.3 \
		Log::Log4perl::NDC.3 \
		Log::Log4perl::Resurrector.3 \
		Log::Log4perl::Util.3 \
		Log::Log4perl::Util::Semaphore.3 \
		Log::Log4perl::Util::TimeTracker.3

.include <bsd.port.mk>
