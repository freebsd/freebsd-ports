# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Proc-Fork
PORTVERSION=	0.801
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Proc::Fork - Simple, intuitive interface to the fork() system call

BUILD_DEPENDS=	p5-Exporter-Tidy>=0:${PORTSDIR}/devel/p5-Exporter-Tidy \
		p5-Object-Tiny-Lvalue>=0:${PORTSDIR}/devel/p5-Object-Tiny-Lvalue
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Proc::Fork.3

.include <bsd.port.mk>
