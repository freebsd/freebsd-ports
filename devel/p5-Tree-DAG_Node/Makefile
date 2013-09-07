# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Tree-DAG_Node
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super class for representing nodes in a tree

BUILD_DEPENDS=	p5-Perl6-Slurp>=0.05.1003:${PORTSDIR}/devel/p5-Perl6-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Tree::DAG_Node.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools
.endif

.include <bsd.port.post.mk>
