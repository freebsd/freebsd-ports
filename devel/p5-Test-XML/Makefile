# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-XML
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compare XML in perl tests

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-SemanticDiff>=0:textproc/p5-XML-SemanticDiff \
		p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
