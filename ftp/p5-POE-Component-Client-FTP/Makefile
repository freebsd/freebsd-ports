# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Client-FTP
PORTVERSION=	0.24
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implements an FTP client POE Component

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=0.38:devel/p5-POE
TEST_DEPENDS=	p5-Test-POE-Client-TCP>=0.1:devel/p5-Test-POE-Client-TCP \
		p5-Test-POE-Server-TCP>=0.16:devel/p5-Test-POE-Server-TCP

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure
CONFIGURE_ENV=	PERL_MM_USE_DEFAULT=yes

SHEBANG_FILES=	examples/*.pl

PORTEXAMPLES=	dotfer.pl list.pl sync.pl

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
