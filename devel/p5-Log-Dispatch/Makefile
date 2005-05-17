# New ports collection makefile for:	devel/p5-Log-Dispatch
# Date created:				17 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A suite of OO modules for logging messages to multiple outputs

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Log::Dispatch.3 \
	Log::Dispatch::ApacheLog.3 \
	Log::Dispatch::Base.3 \
	Log::Dispatch::Email.3 \
	Log::Dispatch::Email::MIMELite.3 \
	Log::Dispatch::Email::MailSend.3 \
	Log::Dispatch::Email::MailSender.3 \
	Log::Dispatch::Email::MailSendmail.3 \
	Log::Dispatch::File.3 \
	Log::Dispatch::File::Locked.3 \
	Log::Dispatch::Handle.3 \
	Log::Dispatch::Output.3 \
	Log::Dispatch::Screen.3 \
	Log::Dispatch::Syslog.3

OPTIONS=	APACHELOG "Apache::Log support" off \
		EMAIL_MIMELITE "MIME::Lite support" off \
		EMAIL_MAILSEND "Mail::Send support" off \
		EMAIL_MAILSENDMAIL "Mail::Sendmail support" on \
		MAIL_SENDER "Mail::Sender support" off

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_APACHELOG)
.if defined(WITH_APACHE2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
.else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
.endif
.endif

.if defined(WITH_EMAIL_MIMELITE)
BUILD_DEPENDS+=	${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite
.endif

.if defined(WITH_EMAIL_MAILSEND)
BUILD_DEPENDS+=	${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools
.endif

.if !defined(WITHOUT_EMAIL_MAILSENDMAIL)
BUILD_DEPENDS+=	${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail
.endif

.if defined(WITH_MAIL_SENDER)
BUILD_DEPENDS+=	${SITE_PERL}/Mail/Sender.pm:${PORTSDIR}/mail/p5-Mail-Sender
.endif

.include <bsd.port.post.mk>
