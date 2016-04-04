# Created by: Blaz Zupan <blaz@amis.net>
# $FreeBSD$

PORTNAME=	Convert-UUlib
PORTVERSION=	1.50
PORTEPOCH=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the uulib library (a.k.a. uudeview/uuenview)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Canary-Stability>=0:devel/p5-Canary-Stability

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Convert/UUlib/UUlib.so

.include <bsd.port.mk>
