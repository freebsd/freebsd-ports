# New ports collection makefile for:	devel/p5-Log-Dispatch
# Date created:				17 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch
PORTVERSION=	2.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A suite of OO modules for logging messages to multiple outputs

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Params-Validate>=0.15:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

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
	Log::Dispatch::File::Locked.3 \
	Log::Dispatch::Handle.3 \
	Log::Dispatch::Null.3 \
	Log::Dispatch::Output.3 \
	Log::Dispatch::Screen.3 \
	Log::Dispatch::Syslog.3

OPTIONS_DEFINE=	APACHELOG EMAIL_MIMELITE EMAIL_MAILSEND EMAIL_MAILSENDMAIL MAIL_SENDER DOCS
OPTIONS_DEFAULT=	EMAIL_MAILSENDMAIL

APACHELOG_DESC=			Apache::Log support
EMAIL_MIMELITE_DESC=		MIME::Lite support
EMAIL_MAILSEND_DESC=		Mail::Send support
EMAIL_MAILSENDMAIL_DESC=	Mail::Sendmail support
MAIL_SENDER_DESC=		Mail::Sender support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHELOG}
USE_APACHE=	20+
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPACHELOG}
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2
.endif

.if ${PORT_OPTIONS:MEMAIL_MIMELITE}
RUN_DEPENDS+=	${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite
.endif

.if ${PORT_OPTIONS:MEMAIL_MAILSEND}
RUN_DEPENDS+=	${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools
.endif

.if ${PORT_OPTIONS:MEMAIL_MAILSENDMAIL}
RUN_DEPENDS+=	${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail
.endif

.if ${PORT_OPTIONS:MMAIL_SENDER}
RUN_DEPENDS+=	${SITE_PERL}/Mail/Sender.pm:${PORTSDIR}/mail/p5-Mail-Sender
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
