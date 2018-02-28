# Created by: Terry Sposato <terry@sucked-in.com>
# $FreeBSD$

PORTNAME=	Sys-CPU
PORTVERSION=	0.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sys::CPU - Perl extension for getting CPU information

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		dos2unix perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sys/CPU/CPU.so

.include <bsd.port.mk>
