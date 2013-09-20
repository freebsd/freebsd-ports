# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Hash-Diff
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Return the difference between two hashes as a hash

RUN_DEPENDS=	p5-Hash-Merge>=0.12:${PORTSDIR}/textproc/p5-Hash-Merge
BUILD_DEPENDS=	p5-Hash-Merge>=0.12:${PORTSDIR}/textproc/p5-Hash-Merge

TEST_DEPENDS=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-use-ok>=0.02:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

MAN3=		Hash::Diff.3

NO_STAGE=	yes
.include <bsd.port.mk>
