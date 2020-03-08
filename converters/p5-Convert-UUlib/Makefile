# Created by: Blaz Zupan <blaz@amis.net>
# $FreeBSD$

PORTNAME=	Convert-UUlib
PORTVERSION=	1.70
PORTEPOCH=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the uulib library (a.k.a. uudeview/uuenview)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/COPYING.Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/COPYING.GNU

BUILD_DEPENDS=	p5-Canary-Stability>=0:devel/p5-Canary-Stability \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-common-sense>=3.74:devel/p5-common-sense

USES=		perl5
USE_CSTD=	c99
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Convert/UUlib/UUlib.so

.include <bsd.port.mk>
