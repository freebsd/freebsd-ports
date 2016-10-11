# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Set
PORTVERSION=	0.39
DISTVERSIONSUFFIX=	00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Datetime sets and set math

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-DateTime>=0.12:devel/p5-DateTime \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Set-Infinite>=0.59:devel/p5-Set-Infinite
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README TODO

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
