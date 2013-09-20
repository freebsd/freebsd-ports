# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Search-Binary
PORTVERSION=	0.95
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module that implements a generic binary search algorithm

USES=		perl5
USE_PERL5=	configure

MAN3=		Search::Binary.3

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|Seach|Search|' \
		${WRKSRC}/Binary.pm

.include <bsd.port.mk>
