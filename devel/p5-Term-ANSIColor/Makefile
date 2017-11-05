# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	Term-ANSIColor
PORTVERSION=	4.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Color screen output using ANSI escape sequences

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	examples/generate-colors

PORTEXAMPLES=	generate-colors

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/generate-colors ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
