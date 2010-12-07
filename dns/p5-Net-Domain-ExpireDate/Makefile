# New ports collection makefile for:	p5-Net-Domain-ExpireDate
# Date created:				Mar 4 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Net-Domain-ExpireDate
PORTVERSION=	1.00
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module obtain expiration date of domain names

RUN_DEPENDS=	${SITE_PERL}/Net/Whois/Raw.pm:${PORTSDIR}/net/p5-Net-Whois-Raw

PERL_CONFIGURE=	yes

MAN3=		Net::Domain::ExpireDate.3

post-patch:
		@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece
.endif

.include <bsd.port.post.mk>
