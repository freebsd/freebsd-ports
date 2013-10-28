# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Class-MakeMethods
PORTVERSION=	1.010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate common types of methods

USES=		perl5
USE_PERL5=	configure

post-extract:
		@${RM} ${WRKSRC}/benchmark.pl
		@${REINPLACE_CMD} -i '' '/benchmark.pl/d' ${WRKSRC}/MANIFEST

.include <bsd.port.mk>
