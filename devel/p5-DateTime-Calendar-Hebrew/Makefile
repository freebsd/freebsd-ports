# Created by: mat
# $FreeBSD$

PORTNAME=	DateTime-Calendar-Hebrew
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dates in the Hebrew calendar

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Event-Sunrise>=0:devel/p5-DateTime-Event-Sunrise
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
