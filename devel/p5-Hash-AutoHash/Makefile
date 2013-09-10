# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	Hash-AutoHash
PORTVERSION=	1.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Object-oriented access to real and tied hashes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tie-Hash-MultiValue>0:${PORTSDIR}/devel/p5-Tie-Hash-MultiValue
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-List-MoreUtils>=0.09:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Tie-ToObject>0:${PORTSDIR}/devel/p5-Tie-ToObject
TEST_DEPENDS=	p5-Test-Deep>0.11:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Hash::AutoHash.3

.include <bsd.port.mk>
