# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Future
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Build objects representing outstanding operations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Identity>0:${PORTSDIR}/devel/p5-Test-Identity \
		p5-Test-Refcount>0:${PORTSDIR}/devel/p5-Test-Refcount \
		p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn

PERL_MODBUILD=	yes

MAN3=		Future.3 Future::Phrasebook.3 Future::Utils.3

PLIST_FILES=	%%SITE_PERL%%/Future.pm %%SITE_PERL%%/Future/Phrasebook.pod \
		%%SITE_PERL%%/Future/Utils.pm
PLIST_DIRS=	%%SITE_PERL%%/Future

.include <bsd.port.mk>
