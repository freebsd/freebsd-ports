# Created by: n-shigemura@ensure.jp
# $FreeBSD$

PORTNAME=	Number-Phone-JP
PORTVERSION=	0.20130603
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TANIGUCHI
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Perl5 module to validate Japanese phone numbers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
TEST_DEPENDS=	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

MAN3=		Number::Phone::JP.3 \
		Number::Phone::JP::Table.3 \

NO_STAGE=	yes
.include <bsd.port.mk>
