# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	File-Pid
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Pid File Manipulation

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		File::Pid.3

post-patch:
	${RM} ${WRKSRC}/lib/File/Pid.pm.orig

.include <bsd.port.mk>
