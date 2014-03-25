# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Text-Iconv
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to iconv() codeset conversion function

USES=		perl5 iconv
USE_PERL5=	configure
CONFIGURE_ARGS+=INC="-I${ICONV_PREFIX}/include ${CFLAGS}" \
		LIBS="-L${ICONV_PREFIX}/lib ${ICONV_LIB}"

.include <bsd.port.mk>
