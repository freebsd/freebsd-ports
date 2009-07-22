# New ports collection makefile for:	p5-Compress-Zlib
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Compress-Zlib
PORTVERSION=	2.015
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 interface to zlib compression library

RUN_DEPENDS=	p5-Compress-Raw-Zlib>=${PORTVERSION}:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		p5-IO-Compress-Base>=${PORTVERSION}:${PORTSDIR}/archivers/p5-IO-Compress-Base \
		p5-IO-Compress-Zlib>=${PORTVERSION}:${PORTSDIR}/archivers/p5-IO-Compress-Zlib

PERL_CONFIGURE=	YES

MAN3=		Compress::Zlib.3

post-patch:
	@${REINPLACE_CMD} -e 's/5.009/5.666/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
