PORTNAME=	System-Info
DISTVERSION=	0.058
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkeenan@cpan.org
COMMENT=	Extract system info for reporting
WWW=		https://metacpan.org/release/System-Info

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_RUN_DEPENDS=	p5-Test-Simple>=0.88:devel/p5-Test-Simple \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
