PORTNAME=	BS-Event
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ELMEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Class that provides an event callback interface

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	samples/simple_example
perl_OLD_CMD=	/opt/perl/bin/perl

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/samples/simple_example ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
