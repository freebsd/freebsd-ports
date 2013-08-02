# Created by: June-Yen Huang <jihuang@gate.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	VCP-Source-cvsbk
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	VCP source driver for bk exported cvs repository

BUILD_DEPENDS=	p5-VCP-autrijus>=0:${PORTSDIR}/devel/p5-VCP-autrijus
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		VCP::Source::cvsbk.3 \
		VCP::Filter::cvsbkchangeset.3

.include <bsd.port.mk>
