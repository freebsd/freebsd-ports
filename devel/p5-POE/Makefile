# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE
PORTVERSION=	1.367
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multitasking and networking framework for perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Curses>=1.08:devel/p5-Curses \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Pipely>=0.005:devel/p5-IO-Pipely \
		p5-IO-Tty>=1.08:devel/p5-IO-Tty \
		p5-POE-Test-Loops>=1.360:devel/p5-POE-Test-Loops \
		p5-Socket-GetAddrInfo>=0.20:net/p5-Socket-GetAddrInfo \
		p5-Term-ReadKey>=2.21:devel/p5-Term-ReadKey \
		p5-URI>=1.30:net/p5-URI \
		p5-libwww>=5.79:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--default
NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	configure

PORTEXAMPLES=	*

SHEBANG_FILES=	examples/*.perl lib/POE/Wheel/Curses.pm

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
