PORTNAME=	Time-Piece
PORTVERSION=	1.40
PORTEPOCH=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ESAYM
PKGNAMEPREFIX=	p5-
MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object-oriented time objects for Perl
WWW=		https://metacpan.org/release/Time-Piece

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Time/Piece/Piece.so

.include <bsd.port.mk>
