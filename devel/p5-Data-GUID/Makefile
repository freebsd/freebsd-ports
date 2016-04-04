# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-GUID
PORTVERSION=	0.047
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Generate globally unique identifiers

BUILD_DEPENDS=	p5-Sub-Install>=0.03:devel/p5-Sub-Install \
		p5-Sub-Exporter>=0.90:devel/p5-Sub-Exporter \
		p5-Data-UUID>=1.148:devel/p5-Data-UUID
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
