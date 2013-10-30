# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch
PORTVERSION=	2.41
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Suite of OO modules for logging messages to multiple outputs

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Dist-CheckConflicts>=0.02:${PORTSDIR}/devel/p5-Dist-CheckConflicts \
		p5-Params-Validate>=0.15:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	APACHELOG MIMELITE MAILSEND MAILSENDER MAILSENDMAIL DOCS
OPTIONS_DEFAULT=MAILSENDMAIL
APACHELOG_DESC=		Apache::Log support
MIMELITE_DESC=		MIME::Lite support
MAILSEND_DESC=		Mail::Send support
MAILSENDER_DESC=	Mail::Sender support
MAILSENDMAIL_DESC=	Mail::Sendmail support

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHELOG}
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MMIMELITE}
RUN_DEPENDS+=	p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite
.endif

.if ${PORT_OPTIONS:MMAILSEND}
RUN_DEPENDS+=	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
.endif

.if ${PORT_OPTIONS:MMAILSENDER}
RUN_DEPENDS+=	p5-Mail-Sender>=0:${PORTSDIR}/mail/p5-Mail-Sender
.endif

.if ${PORT_OPTIONS:MMAILSENDMAIL}
RUN_DEPENDS+=	p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
