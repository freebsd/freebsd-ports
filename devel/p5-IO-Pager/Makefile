# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	IO-Pager
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Select a pager, optionally pipe it output if destination is a TTY

# upstream goof-up. Hopefully can be removed in next update
WRKSRC=		${WRKDIR}/${DISTNAME:C/33/32/}

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
