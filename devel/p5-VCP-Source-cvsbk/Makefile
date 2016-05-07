# Created by: June-Yen Huang <jihuang@gate.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	VCP-Source-cvsbk
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	VCP source driver for bk exported cvs repository

BUILD_DEPENDS=	p5-VCP-autrijus>=0:devel/p5-VCP-autrijus \
		p5-Module-Install>0:devel/p5-Module-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	# Really old M::I code
	${RM} -rf ${WRKSRC}/inc

.include <bsd.port.mk>
