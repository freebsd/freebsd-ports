PORTNAME=	Date-Simple
PORTVERSION=	3.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple date object

LICENSE=	ART10 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Date/Simple/Simple.so

.include <bsd.port.mk>
