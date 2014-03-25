# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Text-Iconv
PORTVERSION=	1.7
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to iconv() codeset conversion function

USES=		perl5 iconv
USE_PERL5=	configure
CONFIGURE_ARGS+=	INC="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}" \
		ccflags="${CFLAGS}"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 1000043
	@${REINPLACE_CMD} 's|<iconv.h>|"/usr/include/iconv.h"|' \
		${WRKSRC}/Iconv.xs
.endif

.include <bsd.port.post.mk>
