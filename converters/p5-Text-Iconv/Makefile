PORTNAME=	Text-Iconv
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to iconv() codeset conversion function

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 iconv:translit
USE_PERL5=	configure
CONFIGURE_ARGS+=INC="-I${ICONV_PREFIX}/include ${CFLAGS}" \
		LIBS="-L${ICONV_PREFIX}/lib ${ICONV_LIB}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/Iconv/Iconv.so

.include <bsd.port.mk>
