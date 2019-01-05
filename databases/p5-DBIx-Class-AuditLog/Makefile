# $FreeBSD$

PORTNAME=	DBIx-Class-AuditLog
PORTVERSION=	0.6.4
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Simple activity audit logging for DBIx::Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build>=0.28:devel/p5-Module-Build
RUN_DEPENDS=	p5-Class-C3-Componentised>=0:devel/p5-Class-C3-Componentised \
		p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-DBIx-Class-TimeStamp>=0:databases/p5-DBIx-Class-TimeStamp
TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:databases/p5-DBICx-TestDatabase \
		p5-DBIx-Class-ResultSet-RecursiveUpdate>=0:databases/p5-DBIx-Class-ResultSet-RecursiveUpdate

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	modbuild

post-install:
	@${MKDIR}                  ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/auto/share/dist/${PORTNAME}
	@${CP} -rp ${WRKSRC}/utils ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/auto/share/dist/${PORTNAME}/

.include <bsd.port.mk>
