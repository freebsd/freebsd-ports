# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Cache
PORTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Perl Cache interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Digest-SHA1>=2.01:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-File-NFSLock>=1.2:${PORTSDIR}/devel/p5-File-NFSLock \
		p5-Heap>=0.01:${PORTSDIR}/devel/p5-Heap \
		p5-IO-String>=1.02:${PORTSDIR}/devel/p5-IO-String \
		p5-TimeDate>=2.24:${PORTSDIR}/devel/p5-TimeDate

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
