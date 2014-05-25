# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Append-TempFile
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Append data to files using a temporary copy

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
