# New ports collection makefile for:	p5-Log-Agent
# Date created:				24 Apr 2001
# Whom:					Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	Log-Agent
PORTVERSION=	0.300
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesse@gallup.com

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Log::Agent.3 \
		Log::Agent::Tag_List.3 \
		Log::Agent::Tag::Callback.3 \
		Log::Agent::Channel.3 \
		Log::Agent::Driver::File.3 \
		Log::Agent::Driver::Fork.3 \
		Log::Agent::Tag.3 \
		Log::Agent::Driver::Syslog.3 \
		Log::Agent::Tag::Caller.3 \
		Log::Agent::Driver::Default.3 \
		Log::Agent::Tag::String.3 \
		Log::Agent::Stamping.3 \
		Log::Agent::Message.3 \
		Log::Agent::Channel::File.3 \
		Log::Agent::Channel::Syslog.3 \
		Log::Agent::Driver::Silent.3 \
		Log::Agent::Priorities.3 \
		Log::Agent::Driver.3 \
		Log::Agent::Tag::Priority.3 \
		Log::Agent::Channel::Handle.3 \
		Log::Agent::Driver::Datum.3 \
		Log::Agent::File::Native.3

.include <bsd.port.mk>
