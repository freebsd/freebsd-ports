# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	Tree-Simple-View
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of classes for viewing Tree::Simple hierarchies

BUILD_DEPENDS=	p5-Tree-Simple>=0:${PORTSDIR}/devel/p5-Tree-Simple \
		p5-Class-Throwable>=0:${PORTSDIR}/devel/p5-Class-Throwable \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-LongString>=0:${PORTSDIR}/devel/p5-Test-LongString
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Tree::Simple::View.3 \
		Tree::Simple::View::ASCII.3 \
		Tree::Simple::View::DHTML.3 \
		Tree::Simple::View::Exceptions.3 \
		Tree::Simple::View::HTML.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
