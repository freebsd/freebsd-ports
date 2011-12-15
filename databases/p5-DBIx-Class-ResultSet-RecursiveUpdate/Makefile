# New ports collection makefile for:	DBIx::Class::ResultSet::RecursiveUpdate
# Date created:		25 Mar 2009
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-ResultSet-RecursiveUpdate
PORTVERSION=	0.24
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Like update_or_create - but recursive

BUILD_DEPENDS=	p5-DBD-SQLite>=1.21:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08100:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-IntrospectableM2M>=0:${PORTSDIR}/databases/p5-DBIx-Class-IntrospectableM2M \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-SQL-Translator>=0.09004:${PORTSDIR}/databases/p5-SQL-Translator
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv2

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::ResultSet::RecursiveUpdate.3

post-extract:
	@${FIND} ${WRKSRC} -name .DS_Store -delete

.include <bsd.port.mk>
