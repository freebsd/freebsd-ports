# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Tie-ToObject
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Tie to an existing object

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${REINPLACE_CMD} -e '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
