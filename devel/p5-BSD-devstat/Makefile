# $FreeBSD$

PORTNAME=	BSD-devstat
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of devstat(3) API

USES=		perl5
USE_PERL5=	configure

MAN3=	BSD::devstat.3

NO_STAGE=	yes
regression-test:
	cd ${WRKSRC} && make test

.include <bsd.port.mk>
