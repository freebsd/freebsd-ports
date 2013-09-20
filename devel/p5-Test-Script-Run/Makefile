# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Script-Run
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Test the script with run

RUN_DEPENDS=	p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Test::Script::Run.3

NO_STAGE=	yes
.include <bsd.port.mk>
