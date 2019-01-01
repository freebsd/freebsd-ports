# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sys-Info
PORTVERSION=	0.7811
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fetch information from the host system

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sys-Info-Base>=0.7800:devel/p5-Sys-Info-Base \
		p5-Sys-Info-Driver-BSD>=0.7800:devel/p5-Sys-Info-Driver-BSD
TEST_DEPENDS=	p5-Test-Sys-Info>=0.20:devel/p5-Test-Sys-Info

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
