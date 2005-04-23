# New ports collection makefile for:	p5-Net-Domain-ExpireDate
# Date created:				Mar 4 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Net-Domain-ExpireDate
PORTVERSION=	0.34
CATEGORIES=	dns net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module obtain expiration date of domain names

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/Net/Whois/Raw.pm:${PORTSDIR}/net/p5-Net-Whois-Raw
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Domain::ExpireDate.3

.include <bsd.port.mk>
