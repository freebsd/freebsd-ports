# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IPC-Cmd
PORTVERSION=	0.84
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Finding and running system commands made easy

COMMON_DEPENDS=	p5-IPC-Run>=0.55:devel/p5-IPC-Run
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
