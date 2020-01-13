# Created by: Zeus Panchenko <zeus@gnu.org.ua>
# $FreeBSD$

PORTNAME=	Config-AST
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Abstract syntax tree for configuration files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-Text-Locus>=1.01:textproc/p5-Text-Locus

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
