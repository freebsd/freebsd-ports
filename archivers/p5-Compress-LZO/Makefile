# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Compress-LZO
PORTVERSION=	1.08
PORTREVISION=	2
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the LZO compression library

LIB_DEPENDS=	lzo2:${PORTSDIR}/archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include/lzo
PERL_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile.PL

MAN3=		Compress::LZO.3

.include <bsd.port.mk>
