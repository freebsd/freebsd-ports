# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-RSS-Headlines
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin that provides RSS headline retrieval

BUILD_DEPENDS=	p5-POE>=1.004:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-IRC>=5.07:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE-Component-Client-HTTP>=0.73:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-XML-RSS>=1.1:${PORTSDIR}/textproc/p5-XML-RSS \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message
RUN_DEPENDS:=	p5-POE>=1.004:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-IRC>=5.07:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE-Component-Client-HTTP>=0.73:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-XML-RSS>=1.1:${PORTSDIR}/textproc/p5-XML-RSS \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Component::IRC::Plugin::RSS::Headlines.3

NO_STAGE=	yes
post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
