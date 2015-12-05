# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MongoDB
PORTVERSION=	1.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mongo Driver for Perl

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Authen-SCRAM>=0.003:${PORTSDIR}/security/p5-Authen-SCRAM \
		p5-Class-XSAccessor>0:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-DateTime>=0.78:${PORTSDIR}/devel/p5-DateTime \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-Safe-Isa>=0:${PORTSDIR}/devel/p5-Safe-Isa \
		p5-Syntax-Keyword-Junction>=0:${PORTSDIR}/devel/p5-Syntax-Keyword-Junction \
		p5-Throwable>=0:${PORTSDIR}/devel/p5-Throwable \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-boolean>=0:${PORTSDIR}/devel/p5-boolean \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Config-AutoConf>=0.220:${PORTSDIR}/devel/p5-Config-AutoConf \
		p5-Path-Tiny>=0.052:${PORTSDIR}/devel/p5-Path-Tiny
TEST_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Deep>=0.111:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

PORTSCOUT=	skipv:0.999.998.5

CFLAGS+=	-DBSON_COMPILATION -DMONGO_USE_64_BIT_INT
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/MongoDB/MongoDB.so

.include <bsd.port.mk>
