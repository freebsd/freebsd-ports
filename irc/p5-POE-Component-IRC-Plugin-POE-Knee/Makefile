# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-POE-Knee
PORTVERSION=	1.12
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE::Component::IRC plugin that runs Acme::POE::Knee races

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Math-Random>=0.69:math/p5-Math-Random \
		p5-POE>=0:devel/p5-POE \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PORTEXAMPLES=	*
SHEBANG_FILES=	examples/*.pl

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
