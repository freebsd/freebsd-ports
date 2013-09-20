# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Iterator-IO
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filesystem and stream iterators

BUILD_DEPENDS=	p5-Iterator>=0:${PORTSDIR}/devel/p5-Iterator
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Iterator::IO.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
