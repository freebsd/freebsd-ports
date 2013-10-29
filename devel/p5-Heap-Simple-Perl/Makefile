# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	Heap-Simple-Perl
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure perl implementation of the Heap::Simple interface

BUILD_DEPENDS=	p5-Heap-Simple>=0:${PORTSDIR}/devel/p5-Heap-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=	-n

.include <bsd.port.mk>
