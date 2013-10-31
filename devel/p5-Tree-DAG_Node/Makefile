# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Tree-DAG_Node
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Super class for representing nodes in a tree

BUILD_DEPENDS=	p5-File-Slurp>=9999.19:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-Temp>=0.23.01:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools
.endif

.include <bsd.port.post.mk>
