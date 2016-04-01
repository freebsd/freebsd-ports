# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	Proc-WaitStat
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Interpret and act on wait() status values

BUILD_DEPENDS=	p5-IPC-Signal>=0:devel/p5-IPC-Signal
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
