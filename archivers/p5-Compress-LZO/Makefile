# New ports collection makefile for:	p5-Compress-LZO
# Date created:		2006-09-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Compress-LZO
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Interface to the LZO compression library

LIB_DEPENDS=	lzo2:${PORTSDIR}/archivers/lzo2

CFLAGS+=	-I${LOCALBASE}/include/lzo
PERL_CONFIGURE=	yes

post-patch:
	${PERL} -pi -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

MAN3=		Compress::LZO.3

.include <bsd.port.mk>
