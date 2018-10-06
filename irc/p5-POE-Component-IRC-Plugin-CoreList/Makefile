# Created by: Martin Wilke <miwi@FreeBSD.org
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-CoreList
PORTVERSION=	1.06
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IRC plugin that provides CoreList goodness

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
