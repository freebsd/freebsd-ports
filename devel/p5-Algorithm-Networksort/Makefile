# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	Algorithm-Networksort
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that will create sorting networks

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moose>=2.1600:devel/p5-Moose \
		p5-namespace-autoclean>=0.16:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		dos2unix perl5
USE_PERL5=	configure

.include <bsd.port.mk>
