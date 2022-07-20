PORTNAME=	Class-Tangram
PORTVERSION=	1.57
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create constructors, accessor, update methods for objects from Tangram

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Set-Object>=0:devel/p5-Set-Object \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Tangram>=0:databases/p5-Tangram

USES=		perl5
USE_PERL5=	configure

post-patch:
		@${REINPLACE_CMD} -i '' -e 's|\@|\\@|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
