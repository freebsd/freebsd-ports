# Created by: James E Keenan <jkeenan@cpan.org>

PORTNAME=	B-Debug
PORTVERSION=	1.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RURBAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkeenan@cpan.org
COMMENT=	Walk Perl syntax tree, printing debug info about ops

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PORTDOCS=	Changes README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
