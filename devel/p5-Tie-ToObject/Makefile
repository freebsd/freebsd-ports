# New ports collection makefile for:	p5-Tie-ToObject
# Date created:		2008-02-13
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Tie-ToObject
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Tie to an existing object

PERL_CONFIGURE=	yes

MAN3=		Tie::ToObject.3

post-extract:
	@${REINPLACE_CMD} -e '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
