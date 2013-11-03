# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Class-Inflate
PORTVERSION=	0.07
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Inflate HASH Object from Values in Database

RUN_DEPENDS=	p5-Devel-Messenger>=0:${PORTSDIR}/devel/p5-Devel-Messenger
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Debugger>=0:${PORTSDIR}/devel/p5-Test-Debugger

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
