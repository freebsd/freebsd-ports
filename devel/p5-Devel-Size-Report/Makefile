# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	Devel-Size-Report
PORTVERSION=	0.13
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate a size report for all elements in a structure

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Array-RefElem>=1.00:misc/p5-Array-RefElem \
		p5-Devel-Size>=0.69:devel/p5-Devel-Size

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
