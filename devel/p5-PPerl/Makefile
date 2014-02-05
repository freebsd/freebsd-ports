# Created by: ijliao
# $FreeBSD$

PORTNAME=	PPerl
PORTVERSION=	0.25
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSERGEANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Make perl scripts persistent in memory

USES=		perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/PPerl/PPerl.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pperl

.include <bsd.port.mk>
