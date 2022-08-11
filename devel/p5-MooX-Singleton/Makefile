PORTNAME=	MooX-Singleton
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Turn your Moo class into singleton

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moo>=0.009013:devel/p5-Moo
RUN_DEPENDS=	p5-Moo>=0.009013:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/MooX/Singleton.pm \
		${SITE_MAN3_REL}/MooX::Singleton.3.gz

.include <bsd.port.mk>
