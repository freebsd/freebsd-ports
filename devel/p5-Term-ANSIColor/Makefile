# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	Term-ANSIColor
PORTVERSION=	4.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	Color screen output using ANSI escape sequences

OPTIONS_DEFINE= EXAMPLES

USES=		perl5
USE_PERL5=	configure

PORTEXAMPLES=	generate-colors

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/generate-colors \
	    ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
