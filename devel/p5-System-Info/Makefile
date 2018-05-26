# Created by: James E Keenan <jkeenan@cpan.org>
# $FreeBSD$

PORTNAME=	System-Info
PORTVERSION=	0.058
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkeenan@cpan.org
COMMENT=	Extract system info for reporting

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Test-Simple>=0.88:devel/p5-Test-Simple \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5 tar:tgz
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	ChangeLog README

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
