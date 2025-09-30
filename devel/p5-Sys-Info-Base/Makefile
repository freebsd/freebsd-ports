PORTNAME=	Sys-Info-Base
PORTVERSION=	0.7810
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Base class for Sys::Info
WWW=		https://metacpan.org/release/Sys-Info-Base

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sys-HostIP>=0:sysutils/p5-Sys-HostIP \
		p5-Text-Template-Simple>=0:textproc/p5-Text-Template-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
