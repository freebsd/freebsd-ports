# Created by: tobez
# $FreeBSD$

PORTNAME=	GraphViz
PORTVERSION=	2.14
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GraphViz - Perl interface to the GraphViz graphing tool

BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
    		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		dot:${PORTSDIR}/graphics/graphviz

USES=		perl5
USE_PERL5=	configure

.if defined(MAINTAINER_MODE)
regression-test: build
	cd ${WRKSRC} && ${MAKE} test
.endif

.include <bsd.port.mk>
