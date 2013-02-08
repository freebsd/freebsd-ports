# Created by: Christopher Boumenot <boumenot@gmail.com>
# $FreeBSD$

PORTNAME=	Algorithm-Bucketizer
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Distribute sized items to buckets with limited size

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Permute>=0:${PORTSDIR}/devel/p5-Algorithm-Permute \
		p5-Sysadm-Install>=0.23:${PORTSDIR}/sysutils/p5-Sysadm-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		bucketize.1
MAN3=		Algorithm::Bucketizer.3

.include <bsd.port.mk>
