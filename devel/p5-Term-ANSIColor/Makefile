PORTNAME=	Term-ANSIColor
PORTVERSION=	5.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Color screen output using ANSI escape sequences

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	examples/generate-colors

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	generate-colors

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/generate-colors ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
