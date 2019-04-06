# Created by: Jerry Hicks <wghicks@bellsouth.net>
# $FreeBSD$

PORTNAME=	Parse-RecDescent
PORTVERSION=	1.967015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Recursive descent parsing framework for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Warn>=0:devel/p5-Test-Warn

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutorial/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
