PORTNAME=	POE-Component-IRC-Plugin-RSS-Headlines
PORTVERSION=	1.10
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE::Component::IRC plugin that provides RSS headline retrieval

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-POE>=1.004:devel/p5-POE \
		p5-POE-Component-Client-HTTP>=0.73:www/p5-POE-Component-Client-HTTP \
		p5-POE-Component-IRC>=5.07:irc/p5-POE-Component-IRC \
		p5-XML-RSS>=1.1:textproc/p5-XML-RSS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
