# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Spoon
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Spiffy Application Building Framework

BUILD_DEPENDS=	p5-Spiffy>=0:devel/p5-Spiffy \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
