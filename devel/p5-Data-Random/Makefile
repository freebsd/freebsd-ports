# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Random
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for generating random data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-YAML-Tiny>=0:${PORTSDIR}/textproc/p5-YAML-Tiny

OPTIONS_DEFINE=	DATE_CALC GD
OPTIONS_DEFAULT=	DATE_CALC
DATE_CALC_DESC=	Support for rand_date()
GD_DESC=	Support for rand_image()

USES=		perl5
USE_PERL5=	configure

MAN3=		Data::Random.3 Data::Random::WordList.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATE_CALC}
BUILD_DEPENDS+=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc
RUN_DEPENDS+=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc
.endif

.if ${PORT_OPTIONS:MGD}
BUILD_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
.endif

.include <bsd.port.mk>
