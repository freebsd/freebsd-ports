# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sub-Exporter-ForMethods
PORTVERSION=	0.100052
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helper routines for using Sub::Exporter to build methods

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-Sub-Exporter>=0.978:devel/p5-Sub-Exporter
BUILD_DEPENDS:=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
