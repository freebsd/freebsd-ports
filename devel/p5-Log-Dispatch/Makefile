# $FreeBSD$

PORTNAME=	Log-Dispatch
PORTVERSION=	2.45
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Suite of OO modules for logging messages to multiple outputs

LICENSE=	ART20

BUILD_DEPENDS=	p5-Devel-GlobalDestruction>=0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Dist-CheckConflicts>=0.02:${PORTSDIR}/devel/p5-Dist-CheckConflicts \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Params-Validate>=0.15:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	APACHELOG MIMELITE MAILSEND MAILSENDER MAILSENDMAIL
OPTIONS_DEFAULT=MAILSENDMAIL
APACHELOG_DESC=		Apache::Log support
MIMELITE_DESC=		MIME::Lite support
MAILSEND_DESC=		Mail::Send support
MAILSENDER_DESC=	Mail::Sender support
MAILSENDMAIL_DESC=	Mail::Sendmail support

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

APACHELOG_RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2
APACHELOG_USE=		APACHE_RUN=22+
MIMELITE_RUN_DEPENDS=	p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite
MAILSEND_RUN_DEPENDS=	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
MAILSENDER_RUN_DEPENDS=	p5-Mail-Sender>=0:${PORTSDIR}/mail/p5-Mail-Sender
MAILSENDMAIL_RUN_DEPENDS=	p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail

.include <bsd.port.mk>
