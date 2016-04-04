# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Locale-Maketext-Lexicon
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Locale/DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use other catalog formats in Locale::Maketext

LICENSE=	MIT

RUN_DEPENDS=	p5-Locale-Maketext>=1.17:devel/p5-Locale-Maketext

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS Changes README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
