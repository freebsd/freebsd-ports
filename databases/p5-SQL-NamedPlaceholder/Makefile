# $FreeBSD$

PORTNAME=	SQL-NamedPlaceholder
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:SATOH
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Extension of placeholder

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Build>=0:devel/p5-Module-Build \
		p5-Module-Build-Tiny>=0.035:devel/p5-Module-Build-Tiny
RUN_DEPENDS=	p5-Exporter-Lite>=0:devel/p5-Exporter-Lite
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuild
PLIST_FILES=	${SITE_PERL_REL}/SQL/NamedPlaceholder.pm \
		${SITE_MAN3_REL}/SQL::NamedPlaceholder.3.gz

NO_ARCH=	yes

.include <bsd.port.mk>
