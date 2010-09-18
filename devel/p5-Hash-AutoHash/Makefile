# New ports collection makefile for:	p5-Hash-AutoHash
# Date created:				2010-09-13
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	Hash-AutoHash
PORTVERSION=	1.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	frederic@culot.org
COMMENT=	Object-oriented access to real and tied hashes

BUILD_DEPENDS=	p5-Tie-Hash-MultiValue>0:${PORTSDIR}/devel/p5-Tie-Hash-MultiValue
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-List-MoreUtils>=0.09:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Tie-ToObject>0:${PORTSDIR}/devel/p5-Tie-ToObject
TEST_DEPENDS=	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep

PERL_MODBUILD=	5.8.3+

MAN3=		Hash::AutoHash.3

.include <bsd.port.mk>
