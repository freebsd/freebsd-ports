# Created by: Koen Martens <gmc@sonologic.nl>
# $FreeBSD$

PORTNAME=	Net-DNS-Resolver-Programmable
PORTVERSION=	0.009
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gmc@sonologic.nl
COMMENT=	Programmable DNS resolver for off-line testing

LICENSE=	ART10 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-DNS>=0.69:dns/p5-Net-DNS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

PORTDOCS=	CHANGES README TODO
DOCSDIR=	${PREFIX}/share/doc/p5-Net-DNS-Resolver-Programmable

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
