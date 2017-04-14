# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	Term-ANSIColor
PORTVERSION=	4.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	Color screen output using ANSI escape sequences

OPTIONS_DEFINE= EXAMPLES

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	examples/generate-colors

PORTEXAMPLES=	generate-colors

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/generate-colors \
	    ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
