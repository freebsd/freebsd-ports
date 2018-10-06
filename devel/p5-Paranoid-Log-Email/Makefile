# $FreeBSD$

PORTNAME=	Paranoid-Log-Email
PORTVERSION=	2.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	SMTP support for Paranoid::Log

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Paranoid>=2:devel/p5-Paranoid

NO_ARCH=	YES
USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%PERL5_MAN3%%/Paranoid::Log::Email.3.gz \
		%%SITE_PERL%%/Paranoid/Log/Email.pm

.include <bsd.port.mk>
