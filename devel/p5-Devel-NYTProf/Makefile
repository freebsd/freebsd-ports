# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	Devel-NYTProf
PORTVERSION=	5.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Powerful feature-rich Perl source code profiler

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0.60:${PORTSDIR}/devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/Devel/NYTProf/NYTProf.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/Devel/auto/Devel/NYTProf/NYTProf.so

.include <bsd.port.mk>
