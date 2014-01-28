# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	Encode
PORTVERSION=	2.55
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANKOGAI
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Provides interfaces between strings and the rest of the system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|bin/enc2xs||; s|bin/piconv||' ${WRKSRC}/Makefile.PL

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
