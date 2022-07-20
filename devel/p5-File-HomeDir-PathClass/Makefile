PORTNAME=	File-HomeDir-PathClass
PORTVERSION=	1.112060
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File::HomeDir returning Path::Class objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=0.93:devel/p5-File-HomeDir \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
