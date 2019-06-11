# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sub-Prototype
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set a sub's prototype #'

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sub-Exporter>=0:devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sub/Prototype/Prototype.so

.include <bsd.port.mk>
