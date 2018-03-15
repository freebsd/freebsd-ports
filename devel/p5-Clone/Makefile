# $FreeBSD$

PORTNAME=	Clone
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Clone - recursively copy Perl datatypes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	patch configure

post-patch:
	${PERL} -pi -e 'm.OPTIMIZE.&&s,.,,sg' ${WRKSRC}/Makefile.PL

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/${SITE_ARCH_REL}/auto/Clone/Clone.so

.include <bsd.port.mk>
