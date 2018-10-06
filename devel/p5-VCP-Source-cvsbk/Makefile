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

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-VCP-autrijus>=0:devel/p5-VCP-autrijus \
		p5-Module-Install>0:devel/p5-Module-Install

USES=		perl5
USE_PERL5=	configure

post-patch:
	# Really old M::I code
	${RM} -r ${WRKSRC}/inc

.include <bsd.port.mk>
