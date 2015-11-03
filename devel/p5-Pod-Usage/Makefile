# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-Usage
PORTVERSION=	1.67
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Print a usage message from embedded pod documentation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5
NO_ARCH=	yes

post-install:
# Do not conflict with lang/perl5.*
	@${RM} ${STAGEDIR}${PREFIX}/bin/pod2usage ${STAGEDIR}${SITE_MAN1}/pod2usage.1
	@${RMDIR} ${STAGEDIR}${SITE_MAN1}

.include <bsd.port.mk>
