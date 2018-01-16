# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Const-Exporter
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RRWO
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Declare constants for export

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Const-Fast>=0:devel/p5-Const-Fast \
		p5-Package-Stash>=0:devel/p5-Package-Stash \
		p5-Ref-Util>=0:devel/p5-Ref-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Hash-Objectify>=0:devel/p5-Hash-Objectify \
		p5-Path-Tiny>=0.004:devel/p5-Path-Tiny \
		p5-Test-Most>=0:devel/p5-Test-Most

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
