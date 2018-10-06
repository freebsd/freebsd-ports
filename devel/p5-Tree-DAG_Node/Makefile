# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Tree-DAG_Node
PORTVERSION=	1.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super class for representing nodes in a tree

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurp-Tiny>=0.003:devel/p5-File-Slurp-Tiny

NO_ARCH=	yes
USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
