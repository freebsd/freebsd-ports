PORTNAME=	Tie-ToObject
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie to an existing object

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
