# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Search-Xapian
PORTVERSION=	1.0.23.0
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION:R}/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	10

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl XS frontend to the Xapian C++ search library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Depend on unsupported xapian-core. Use databases/p5-Search-Xapian instead
EXPIRATION_DATE=2020-06-30

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	xapian-core10>=1.0.22:databases/xapian-core10

CONFLICTS_INSTALL=	p5-Search-Xapian12

USES=		perl5
USE_PERL5=	configure

CC=		${CXX}

post-patch:
	@${REINPLACE_CMD} -e 's/^if (defined $$builddir/if (0/' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Search/Xapian/Xapian.so

.include <bsd.port.mk>
