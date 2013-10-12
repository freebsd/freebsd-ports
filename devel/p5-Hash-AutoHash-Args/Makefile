# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Hash-AutoHash-Args
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented processing of keyword-based argument lists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

#		p5-Scalar-List-Utils>=1.32:${PORTSDIR}/lang/p5-Scalar-List-Utils
#		p5-List-MoreUtils>=0.33:${PORTSDIR}/lang/p5-List-MoreUtils
BUILD_DEPENDS=	p5-Hash-AutoHash>=1.17:${PORTSDIR}/devel/p5-Hash-AutoHash
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0.110:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Pod>=1.48:${PORTSDIR}/devel/p5-Test-Pod

NO_STAGE=	yes
USE_PERL5=	modbuild
USES=		perl5

MAN3=		Hash::AutoHash::Args.3 \
		Hash::AutoHash::Args::V0.3

.include <bsd.port.mk>
