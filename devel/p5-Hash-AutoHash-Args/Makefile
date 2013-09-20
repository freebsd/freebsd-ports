# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Hash-AutoHash-Args
PORTVERSION=	1.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented processing of keyword-based argument lists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Hash-AutoHash>=1.16:${PORTSDIR}/devel/p5-Hash-AutoHash
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	modbuild
USES=		perl5

MAN3=		Hash::AutoHash::Args.3 \
		Hash::AutoHash::Args::V0.3

NO_STAGE=	yes
.include <bsd.port.mk>
