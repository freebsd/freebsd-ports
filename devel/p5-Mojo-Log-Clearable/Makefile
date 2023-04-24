PORTNAME=	Mojo-Log-Clearable
PORTVERSION=	1.001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DBOOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Log rotation role for Mojo::Log
WWW=		https://metacpan.org/pod/Mojo::Log::Clearable

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mojolicious>9:www/p5-Mojolicious

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
