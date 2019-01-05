# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-FormHandler-Model-DBIC
PORTVERSION=	0.29
CATEGORIES=	databases perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Model class for FormHandler unsing DBIx::Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBIx-Class>=0.08250:databases/p5-DBIx-Class \
		p5-DBIx-Class-ResultSet-RecursiveUpdate>=0.25:databases/p5-DBIx-Class-ResultSet-RecursiveUpdate \
		p5-HTML-FormHandler>=0.40016:www/p5-HTML-FormHandler \
		p5-Moose>=2.0007:devel/p5-Moose \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-DateTime-Format-MySQL>0:devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-SQLite>0:devel/p5-DateTime-Format-SQLite \
		p5-DateTime-Format-W3CDTF>0:devel/p5-DateTime-Format-W3CDTF \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	configure

.include <bsd.port.mk>
