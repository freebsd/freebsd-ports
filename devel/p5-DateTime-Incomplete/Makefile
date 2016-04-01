# Created by: mat
# $FreeBSD$

PORTNAME=	DateTime-Incomplete
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Incomplete DateTime, like January 5

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Set>=0.14:devel/p5-DateTime-Set \
		p5-DateTime-Event-Recurrence>=0:devel/p5-DateTime-Event-Recurrence
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes MANIFEST README TODO

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
