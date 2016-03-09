# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	ReadLine-Gnu
PORTVERSION=	1.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allow Term::ReadLine to use GNU readline

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5 readline
CFLAGS+=	${CPPFLAGS}
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Term/ReadLine/Gnu/Gnu.so

.include <bsd.port.mk>
