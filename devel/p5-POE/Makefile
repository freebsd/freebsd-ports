# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE
PORTVERSION=	1.356
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multitasking and networking framework for perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Curses>=1.08:${PORTSDIR}/devel/p5-Curses \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-Pipely>=0.005:${PORTSDIR}/devel/p5-IO-Pipely \
		p5-IO-Tty>=1.08:${PORTSDIR}/devel/p5-IO-Tty \
		p5-POE-Test-Loops>=1.352:${PORTSDIR}/devel/p5-POE-Test-Loops \
		p5-Socket-GetAddrInfo>=0.20:${PORTSDIR}/net/p5-Socket-GetAddrInfo \
		p5-Term-ReadKey>=2.21:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-URI>=1.30:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.79:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--default

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

test: build
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
