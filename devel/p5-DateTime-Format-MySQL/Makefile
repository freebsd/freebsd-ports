# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-MySQL
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format MySQL dates and times

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0:${PORTSDIR}/devel/p5-DateTime-Format-Builder

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
