# Created by: tobez
# $FreeBSD$

PORTNAME=	GraphViz
PORTVERSION=	2.24
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to GraphViz graphing tool

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-File-Which>=1.09:sysutils/p5-File-Which
RUN_DEPENDS=	dot:graphics/graphviz \
		p5-IPC-Run>=0.60:devel/p5-IPC-Run \
		p5-Parse-RecDescent>=1.965001:devel/p5-Parse-RecDescent \
		p5-XML-Twig>=3.52:textproc/p5-XML-Twig
TEST_DEPENDS=	p5-Test2-Suite>=0.000030:devel/p5-Test2-Suite

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
