# Created by: tobez
# $FreeBSD$

PORTNAME=	GraphViz
PORTVERSION=	2.24
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GraphViz - Perl interface to the GraphViz graphing tool

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dot:graphics/graphviz \
		p5-IPC-Run>=0.60:devel/p5-IPC-Run \
		p5-Parse-RecDescent>=1.965.001:devel/p5-Parse-RecDescent \
		p5-XML-Twig>=3.52:textproc/p5-XML-Twig
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-File-Which>=1.09:sysutils/p5-File-Which
TEST_DEPENDS=	p5-Test2-Suite>=0.000030:devel/p5-Test2-Suite

NO_ARCH=	yes
USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
