# $FreeBSD$

PORTNAME=	MooX-Locale-Passthrough
PORTVERSION=	0.001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Provide API used in translator modules without translating

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=2.003004:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL_REL}/MooX/Locale/Passthrough.pm \
		${SITE_MAN3_REL}/MooX::Locale::Passthrough.3.gz

NO_ARCH=	yes

.include <bsd.port.mk>
