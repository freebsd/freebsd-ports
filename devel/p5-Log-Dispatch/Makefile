# New ports collection makefile for:	devel/p5-Log-Dispatch
# Date created:				17 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch
PORTVERSION=	2.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A suite of OO modules for logging messages to multiple outputs

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

IS_INTERACTIVE=	yes

USE_SUBMAKE=	yes
PERL_CONFIGURE=	yes

MAN3=	Log::Dispatch.3 \
	Log::Dispatch::ApacheLog.3 \
	Log::Dispatch::Base.3 \
	Log::Dispatch::Email.3 \
	Log::Dispatch::Email::MIMELite.3 \
	Log::Dispatch::Email::MailSend.3 \
	Log::Dispatch::Email::MailSender.3 \
	Log::Dispatch::Email::MailSendmail.3 \
	Log::Dispatch::File.3 \
	Log::Dispatch::Handle.3 \
	Log::Dispatch::Output.3 \
	Log::Dispatch::Screen.3 \
	Log::Dispatch::Syslog.3

SCRIPTS_ENV+=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${PERL} ${SCRIPTDIR}/configure.pl

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
