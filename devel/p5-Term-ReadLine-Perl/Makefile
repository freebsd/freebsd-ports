# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Term-ReadLine-Perl
PORTVERSION=	1.0303
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Quick implementation of the minimal interface to Readline libraries

BUILD_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_STAGE=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
