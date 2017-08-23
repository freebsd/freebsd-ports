# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	List-MoreUtils
PORTVERSION=	0.423
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide the stuff missing in List::Util

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.038:devel/p5-Exporter-Tiny \
		p5-List-MoreUtils-XS>=${PORTVERSION}:lang/p5-List-MoreUtils-XS
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
