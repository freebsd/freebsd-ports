PORTNAME=	JavaScript-SpiderMonkey
PORTVERSION=	0.25
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to Mozilla JavaScript implementation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libjs.so:lang/spidermonkey17
TEST_DEPENDS=	p5-Log-Log4perl>=0:devel/p5-Log-Log4perl

USES=		perl5
USE_PERL5=	configure

CFLAGS+=	-I${LOCALBASE}/include/js-1.7/

post-patch:
	@${REINPLACE_CMD} -e 's|libjs.a|libjs.so|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
