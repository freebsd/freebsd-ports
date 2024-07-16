PORTNAME=	Image-Imlib2
PORTVERSION=	2.03
PORTREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Imlib2 image library
WWW=		https://metacpan.org/release/Image-Imlib2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES=	examples/benchmark.pl examples/benchmark.txt examples/maeda.pl

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include <bsd.port.mk>
